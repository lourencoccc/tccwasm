$dataset_dir = "./dataset"
if (-Not (Test-Path $dataset_dir))
{
    New-Item -ItemType Directory -Force -Path $dataset_dir
}
New-Item -ItemType file '.\dataset.csv' -Force
Add-Content .\dataset.csv 'id;extension;resolution;fps;youtube_link'

#WORKLOAD_1
youtube-dl -f '(mp4)[height=480]/[fps=30]' -o $dataset_dir/WORKLOAD_1.mp4 https://www.youtube.com/watch?v=tznWpTAV41M
Add-Content .\dataset.csv 'WORKLOAD_1;mp4;640x480;30fps;https://www.youtube.com/watch?v=tznWpTAV41M'

#WORKLOAD_2
youtube-dl -f '(mp4)[height=1080]/[fps=30]' -o $dataset_dir/WORKLOAD_2.mp4 https://www.youtube.com/watch?v=vQtLX6pW5eA
Add-Content .\dataset.csv 'WORKLOAD_2;mp4;1920x1080;30fps;https://www.youtube.com/watch?v=vQtLX6pW5eA'

#WORKLOAD_3
youtube-dl -f '(mp4)[height=1080]/[fps=24]' -o $dataset_dir/WORKLOAD_3.mp4 https://www.youtube.com/watch?v=EWUdGRAwUpY
Add-Content .\dataset.csv 'WORKLOAD_3;mp4;1920x1080;24fps;https://www.youtube.com/watch?v=EWUdGRAwUpY'

#WORKLOAD_4
youtube-dl -f '(mp4)[height=480]/[fps=30]' -o $dataset_dir/WORKLOAD_4.mp4 https://www.youtube.com/watch?v=JoWIjjZ6a-k
Add-Content .\dataset.csv 'WORKLOAD_4;mp4;640x480;24fps;https://www.youtube.com/watch?v=JoWIjjZ6a-k'

#WORKLOAD_5
youtube-dl -f '(mp4)[height=720]/[fps=25]' -o $dataset_dir/WORKLOAD_5.mp4 https://www.youtube.com/watch?v=de2Hsvxaf8M
Add-Content .\dataset.csv 'WORKLOAD_5;mp4;1280x720;25fps;https://www.youtube.com/watch?v=de2Hsvxaf8M'

#WORKLOAD_6
youtube-dl -f '(mp4)[height=240]/[fps=30]' -o $dataset_dir/WORKLOAD_6.mp4 https://www.youtube.com/watch?v=ESjTlD606aQ
Add-Content .\dataset.csv 'WORKLOAD_6;mp4;320x240;30fps;https://www.youtube.com/watch?v=ESjTlD606aQ'

#WORKLOAD_7
youtube-dl -f '(mp4)[height=720]/[fps=24]' -o $dataset_dir/WORKLOAD_7.mp4 https://www.youtube.com/watch?v=tGNBdjVO04Y
Add-Content .\dataset.csv 'WORKLOAD_7;mp4;1280x720;24fps;https://www.youtube.com/watch?v=tGNBdjVO04Y'

#WORKLOAD_8
youtube-dl -f '(mp4)[height=1080]/[fps=24]' -o $dataset_dir/WORKLOAD_8.mp4 https://www.youtube.com/watch?v=5XVCf-CAEPk
Add-Content .\dataset.csv 'WORKLOAD_8;mp4;1920x1080;24fps;https://www.youtube.com/watch?v=5XVCf-CAEPk'

#WORKLOAD_9
youtube-dl -f '(mp4)[height=720]/[fps=30]' -o $dataset_dir/WORKLOAD_9.mp4 https://www.youtube.com/watch?v=AZ4tesVagso
Add-Content .\dataset.csv 'WORKLOAD_9;mp4;1280x720;30fps;https://www.youtube.com/watch?v=AZ4tesVagso'

#WORKLOAD_10
youtube-dl -f '(mp4)[height=1080]/[fps=50]' -o $dataset_dir/WORKLOAD_10.mp4 https://www.youtube.com/watch?v=RuL5jVqc4Tg
Add-Content .\dataset.csv 'WORKLOAD_10;mp4;1920x1080;50fps;https://www.youtube.com/watch?v=RuL5jVqc4Tg'


