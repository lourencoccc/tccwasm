#Script to downlaod all videos used as dataset
# Dependencie: http://ytdl-org.github.io/youtube-dl/download.html
$dataset_dir = "$env:PRJROOT/dataset"
if (-Not (Test-Path $dataset_dir)) {
    New-Item -ItemType Directory -Force -Path $dataset_dir
}

Function DownloadVideo($fparam, $name, $youtube_link) {
    if (-Not (Test-Path $dataset_dir/$name.mp4)) {
        youtube-dl -f $fparam -o $dataset_dir/$name.mp4 $youtube_link
    }
}

New-Item -ItemType file dataset.csv -Force
Add-Content dataset.csv 'id,extension,resolution,fps,dyoutube_link'

# #DATASET_1
DownloadVideo '(mp4)[height=1080]/[fps=24]' DATASET_1 https://www.youtube.com/watch?v=EWUdGRAwUpY
Add-Content dataset.csv  'DATASET_1,mp4,1920x1080,24,https://www.youtube.com/watch?v=EWUdGRAwUpY'

# #DATASET_2
DownloadVideo '(mp4)[height=1080]/[fps=30]' DATASET_2 https://www.youtube.com/watch?v=vQtLX6pW5eA
Add-Content dataset.csv  'DATASET_2,mp4,1920x1080,30,https://www.youtube.com/watch?v=vQtLX6pW5eA'

# #DATASET_3
DownloadVideo '(mp4)[height=1080]/[fps=50]' DATASET_3 https://www.youtube.com/watch?v=RuL5jVqc4Tg
Add-Content dataset.csv 'DATASET_3,mp4,1920x1080,50,https://www.youtube.com/watch?v=RuL5jVqc4Tg'
