#!/bin/bash
#SBATCH --mem=1G                # memory per job
#SBATCH --time=00-01:00         # time (DD-HH:MM)
#SBATCH --output=hello_omp.log  # output file
#SBATCH --cpus-per-task=4       # No. of cpus 

./hellow_omp
