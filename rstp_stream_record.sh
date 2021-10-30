# Script to continously record and save the rstp stream(found in most of the wifi/internet camera)
# Pre Requisite . vlc
while :; do
    /usr/bin/vlc -vvv rtsp://username:password@<camera-ip-address>:554/<stream1> --sout=file/ts:/path/to/camera-recording/folder/recording-$(date +"%Y%m%d%H%M%S").ts -I dummy --stop-time=480 vlc://quit ; sleep 1
done
