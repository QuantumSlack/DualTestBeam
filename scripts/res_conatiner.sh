#!/bin/bash

read -p "Enter the starting directory to run Resolution on: " diri
read -p "Enter the finishing directory: " dirf

# Execute the analysis script inside the container
singularity exec -B /cvmfs:/cvmfs -B /cms/data:/cms/data docker://gitlab-registry.cern.ch/sft/docker/alma9-core:latest bash scripts/res.sh "$diri" "$dirf"
