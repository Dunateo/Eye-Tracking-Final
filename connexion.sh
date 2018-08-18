#!/bin/bash
rm -rf /media/sf_Partage/T5/Big-Projectmg/Fichiers/etat.txt
ssh pi@172.20.10.13 -i pass 'chmod +x /home/pi/video.sh;/home/pi/video.sh' & wait
touch /media/sf_Partage/T5/Big-Projectmg/Fichiers/etat.txt
