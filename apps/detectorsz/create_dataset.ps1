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
Add-Content .\dataset.csv 'id;name;extension;resolution;fps;youtube_link'

#WORKLOAD_1
DownloadVideo '(mp4)[height=480]/[fps=30]' WORKLOAD_1 https://www.youtube.com/watch?v=tznWpTAV41M
Add-Content .\dataset.csv '1;WORKLOAD_1;mp4;640x480;30fps;https://www.youtube.com/watch?v=tznWpTAV41M'

# #WORKLOAD_2
DownloadVideo '(mp4)[height=1080]/[fps=30]' WORKLOAD_2 https://www.youtube.com/watch?v=vQtLX6pW5eA
Add-Content .\dataset.csv '2;WORKLOAD_2;mp4;1920x1080;30fps;https://www.youtube.com/watch?v=vQtLX6pW5eA'

# #WORKLOAD_3
DownloadVideo '(mp4)[height=1080]/[fps=24]' WORKLOAD_3 https://www.youtube.com/watch?v=EWUdGRAwUpY
Add-Content .\dataset.csv '3;WORKLOAD_3;mp4;1920x1080;24fps;https://www.youtube.com/watch?v=EWUdGRAwUpY'

# #WORKLOAD_4
DownloadVideo '(mp4)[height=480]/[fps=30]' WORKLOAD_4 https://www.youtube.com/watch?v=JoWIjjZ6a-k
Add-Content .\dataset.csv '4;WORKLOAD_4;mp4;640x480;24fps;https://www.youtube.com/watch?v=JoWIjjZ6a-k'

# #WORKLOAD_5
DownloadVideo '(mp4)[height=720]/[fps=25]' WORKLOAD_5 https://www.youtube.com/watch?v=de2Hsvxaf8M
Add-Content .\dataset.csv '5;WORKLOAD_5;mp4;1280x720;25fps;https://www.youtube.com/watch?v=de2Hsvxaf8M'

# #WORKLOAD_6
DownloadVideo '(mp4)[height=240]/[fps=30]' WORKLOAD_6 https://www.youtube.com/watch?v=ESjTlD606aQ
Add-Content .\dataset.csv '6;WORKLOAD_6;mp4;320x240;30fps;https://www.youtube.com/watch?v=ESjTlD606aQ'

# #WORKLOAD_7
DownloadVideo '(mp4)[height=720]/[fps=24]' WORKLOAD_7 https://www.youtube.com/watch?v=tGNBdjVO04Y
Add-Content .\dataset.csv '7;WORKLOAD_7;mp4;1280x720;24fps;https://www.youtube.com/watch?v=tGNBdjVO04Y'

# #WORKLOAD_8
DownloadVideo '(mp4)[height=1080]/[fps=24]' WORKLOAD_8 https://www.youtube.com/watch?v=5XVCf-CAEPk
Add-Content .\dataset.csv '8;WORKLOAD_8;mp4;1920x1080;24fps;https://www.youtube.com/watch?v=5XVCf-CAEPk'

# #WORKLOAD_9
DownloadVideo '(mp4)[height=720]/[fps=30]' WORKLOAD_9 https://www.youtube.com/watch?v=AZ4tesVagso
Add-Content .\dataset.csv '9;WORKLOAD_9;mp4;1280x720;30fps;https://www.youtube.com/watch?v=AZ4tesVagso'

# #WORKLOAD_10
DownloadVideo '(mp4)[height=1080]/[fps=50]' WORKLOAD_10 https://www.youtube.com/watch?v=RuL5jVqc4Tg
Add-Content .\dataset.csv '10;WORKLOAD_10;mp4;1920x1080;50fps;https://www.youtube.com/watch?v=RuL5jVqc4Tg'
