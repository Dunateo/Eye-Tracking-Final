#!/bin/bash
DATE=`date +%Y-%m-%d`
rm -rf /media/sf_Partage/T5/Big-Projectmg/Vid
scp -i pass -r pi@172.20.10.13:/home/pi/Vid /media/sf_Partage/T5/Big-Projectmg/Vid
ffmpeg -i /media/sf_Partage/T5/Big-Projectmg/Vid/down.mp4 -r 6 -pix_fmt bgr24 /media/sf_Partage/T5/Big-Projectmg/Vid/%d.bmp
touch /media/sf_Partage/T5/Big-Projectmg/Fichiers/etat2.txt
