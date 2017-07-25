/**
 *  analyse.c
 *
 *  Entry points to the Analyse Dynamic Library
 *
 *  25-07-2017 - First Implementation by Guillermo Amodeo
 *
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>

#define CONSTRUCTOR __attribute__((constructor))
#define DESTRUCTOR  __attribute__((destructor))
#define EXPORT_FUNC __attribute__((visibility("default")))


/** --------------------------------------------- *
 *
 * \brief Analyse Library Constructor
 *
 *  This function is called at load time to init
 *  the library put here the common init code.
 *
 * --------------------------------------------- */

CONSTRUCTOR static void constructor(void)
{
    fprintf(stderr,"** Loading analyse() **\n");
}


/** --------------------------------------------- *
 *
 * \brief Analyse Library's Destructor
 *
 *  This function is called at unload time to
 *  free the resources used by the library.
 *  Put here the code to free them.
 *
 * --------------------------------------------- */

DESTRUCTOR static void destructor(void)
{                               // 3
    fprintf(stderr,"**Unloading analyse() **\n");
}


/** --------------------------------------------- *
 *
 * \brief Analyse 'input' and write results in 'output'
 *
 *  This function analyse the file specified by 'input'
 *  and write the results in the file specified by
 *  'output'.
 *
 *  It returns 0 for success or a negative number
 *  for error, which is a negative version of the
 *  standard errors in errno.h
 *
 *  Please note that 'output' would be overwritten
 *  in success and deleted on error.
 * --------------------------------------------- */

 EXPORT_FUNC int analyse(const char *input, const char *output)
 {
    FILE *fp;
    int cnt;
    double sum;
    char buf[128]={0};

    if (!input || !output)
        return -(EINVAL);   // Invalid parameter

    if(access(input,F_OK))
        return -(ENOENT);   // File not found

    fp = fopen(input,"r");
    if(fp==NULL)
        return -(EACCES);    // Permission denied

    // Initialise accumulators

    cnt = 0;   // count of numbers read
    sum = 0.0; // sum

    // Read input file

    do
    {
        if(fgets(buf,128,fp))
        {
            char *ptr=buf;

            // Ignore space chars: ' ', '\t', '\n', '\v', '\f', '\r'

            while(isspace(*ptr))
                ptr++;

            // Ignore anything that is not a valid number like 0, +1.23, -99 or .2

            if(strchr("01234567890+-.",*ptr))
            {
                cnt++;
                sum+=atof(ptr);
                if(isinf(sum))
                {
                    fclose(fp);
                    return -(ERANGE);   // Result too large or too small
                }
            }
        }
        else if(ferror(fp))
        {
            fclose(fp);
            return -(EIO);
        }
    } while(!feof(fp));
    fclose(fp);

    // Now write output

    fp = fopen(output,"w+");
    if(fp==NULL)
        return -(EACCES);   // Permission denied

    if(fprintf(fp,"%d\n%f\n%f\n",cnt,sum,(sum / (double)cnt)) < 0)
    {
        fclose(fp);
        remove(output);
        return  -(EIO);
    }
    fflush(fp);
    fclose(fp);

    return 0;
 }

