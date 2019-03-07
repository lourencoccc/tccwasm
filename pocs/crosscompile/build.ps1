$Solution = "Solution"
if (-Not (Test-Path $Solution))
{
    New-Item -ItemType Directory -Force -Path $Solution
}
cd $Solution
cmake ..
cd ..
