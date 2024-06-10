#!/bin/bash
#SBATCH --cpus-per-task=4       # No. of cpus 
#SBATCH --mem=4G                # memory per job
#SBATCH --time=00-01:00         # time (DD-HH:MM)
#SBATCH --output=hellow_omp.log  # output file

./hellow_omp

