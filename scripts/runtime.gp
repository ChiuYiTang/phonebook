reset
set ylabel 'time(sec)'
set style fill solid
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($2+0.0045):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'hash table'  , \
'' using ($0+0.15):($3+0.0030):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'binary search tree' , \
'' using ($0+0.2):($4+0.0002):4 with labels title ' ', \
'' using 5:xtic(1) with histogram title 'big binary search tree'  , \
'' using ($0+0.4):($5+0.0000):5 with labels title ' 