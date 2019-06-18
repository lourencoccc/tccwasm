#Script to downlaod all videos used as dataset
$dataset_dir = "./dataset"
if (-Not (Test-Path $dataset_dir)) {
    New-Item -ItemType Directory -Force -Path $dataset_dir
}

Function DownloadVideo($fparam, $name, $youtube_link) {
    if (-Not (Test-Path $dataset_dir/$name.mp4)) {
        youtube-dl -f $fparam -o $dataset_dir/$name.mp4 $youtube_link
    }
}

New-Item -ItemType file '.\dataset.csv' -Force
Add-Content .\dataset.csv 'id,extension,resolution,fps,dyoutube_link'

# #DATASET_1
DownloadVideo '(mp4)[height=1080]/[fps=24]' DATASET_1 https://www.youtube.com/watch?v=EWUdGRAwUpY
Add-Content .\dataset.csv 'DATASET_1,mp4,1920x1080,24,https://www.youtube.com/watch?v=EWUdGRAwUpY'

# #DATASET_2
DownloadVideo '(mp4)[height=1080]/[fps=30]' DATASET_2 https://www.youtube.com/watch?v=vQtLX6pW5eA
Add-Content .\dataset.csv 'DATASET_2,mp4,1920x1080,30,https://www.youtube.com/watch?v=vQtLX6pW5eA'

# #DATASET_3
DownloadVideo '(mp4)[height=1080]/[fps=50]' DATASET_3 https://www.youtube.com/watch?v=RuL5jVqc4Tg
Add-Content .\dataset.csv 'DATASET_3,mp4,1920x1080,50,https://www.youtube.com/watch?v=RuL5jVqc4Tg'

# #DATASET_1
# DownloadVideo '(mp4)[height=480]/[fps=30]' DATASET_1 https://www.youtube.com/watch?v=tznWpTAV41M
# Add-Content .\dataset.csv '1;DATASET_1;mp4;640x480;30fps;https://www.youtube.com/watch?v=tznWpTAV41M'

# # #DATASET_4
# DownloadVideo '(mp4)[height=480]/[fps=30]' DATASET_4 https://www.youtube.com/watch?v=JoWIjjZ6a-k
# Add-Content .\dataset.csv '4;DATASET_4;mp4;640x480;24fps;https://www.youtube.com/watch?v=JoWIjjZ6a-k'

# # #DATASET_5
# DownloadVideo '(mp4)[height=720]/[fps=25]' DATASET_5 https://www.youtube.com/watch?v=de2Hsvxaf8M
# Add-Content .\dataset.csv '5;DATASET_5;mp4;1280x720;25fps;https://www.youtube.com/watch?v=de2Hsvxaf8M'

# # #DATASET_6
# DownloadVideo '(mp4)[height=240]/[fps=30]' DATASET_6 https://www.youtube.com/watch?v=ESjTlD606aQ
# Add-Content .\dataset.csv '6;DATASET_6;mp4;320x240;30fps;https://www.youtube.com/watch?v=ESjTlD606aQ'

# # #DATASET_7
# DownloadVideo '(mp4)[height=720]/[fps=24]' DATASET_7 https://www.youtube.com/watch?v=tGNBdjVO04Y
# Add-Content .\dataset.csv '7;DATASET_7;mp4;1280x720;24fps;https://www.youtube.com/watch?v=tGNBdjVO04Y'

# # #DATASET_8
# DownloadVideo '(mp4)[height=1080]/[fps=24]' DATASET_8 https://www.youtube.com/watch?v=5XVCf-CAEPk
# Add-Content .\dataset.csv '8;DATASET_8;mp4;1920x1080;24fps;https://www.youtube.com/watch?v=5XVCf-CAEPk'

# # #DATASET_9
# DownloadVideo '(mp4)[height=720]/[fps=30]' DATASET_9 https://www.youtube.com/watch?v=AZ4tesVagso
# Add-Content .\dataset.csv '9;DATASET_9;mp4;1280x720;30fps;https://www.youtube.com/watch?v=AZ4tesVagso'
