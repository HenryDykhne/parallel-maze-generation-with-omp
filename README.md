# parallel-maze-generation-with-omp

# Operation
## Compilation
Compile with `make`.

## Serial
### Run with:
`./maze <-n #>? <-s #> <-p>??`

### ex:
* `./maze -n 13 -s 221`
* `./maze -n 13 -s 221 -p`
* `./maze -n 13`

## Parallel
### Run with:
* `./mazep -n 13 -s 221`
* `./mazep -n 13 -s 221 -p`
* `./mazep -n 13`
### ex:
`./mazep -n 13 -s 221`

## Misc
* `-n`, `-s` and `-p` arguments are optional. If excluded or invalid, maze size will be set to 11 and the seed to default.
* `-n` must be > 4.
* `-s` must be > 0.
* `-p` will suppress printing of the maze if present.

## Sample output (Will be colored in RGBY if your terminal/monitor supports it)
```
computer:~/Documents/parallel-maze-generation-with-omp$ ./mazep -n 55 -s 43
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
. 0 0 0 . 1 1 1 1 1 1 1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 1 1 . 1 . 1 . 1 1 1 . 1 . 1 1 1 1 1 1 1 . 1 . 1 . 1 1 1 . 
. 0 . . . 1 . 1 . . . 1 . . . 1 . . . 1 . . . . . . . . . 1 . 1 . 1 . . . 1 . . . 1 . . . 1 . 1 . 1 . . . 1 . 
. 0 0 0 . 1 . 1 . 1 1 1 1 1 . 1 1 1 1 1 1 1 . 1 . 1 . 1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 1 1 1 1 . 
. 0 . . . 1 . . . . . 1 . . . 1 . 1 . 1 . . . 1 . 1 . . . 1 . . . 1 . . . 1 . 1 . 1 . . . 1 . 1 . 1 . 1 . 1 . 
. 0 0 0 . 1 1 1 . 1 1 1 1 1 . 1 . 1 . 1 . 1 1 1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 . 1 . 1 . 0 . 1 . 1 . 1 . 1 . 1 . 
. 0 . . . . . 1 . . . 1 . . . . . . . . . . . 1 . 1 . 1 . 1 . . . 1 . 1 . 1 . . . . . 0 . . . . . . . . . . . 
. 0 0 0 0 0 . 1 . 1 1 1 1 1 . 1 . 1 . 1 . 1 1 1 . 1 . 1 . 1 . 0 . 1 . 1 . 1 . 0 . 0 0 0 0 0 0 0 0 0 . 0 . 0 . 
. 0 . 0 . . . 1 . . . 1 . . . 1 . 1 . 1 . . . 1 . . . . . . . 0 . . . . . . . 0 . . . 0 . 0 . . . 0 . 0 . 0 . 
. 0 . 0 0 0 . 1 . 1 1 1 . 1 1 1 1 1 1 1 . 1 1 1 1 1 . 0 . 0 . 0 0 0 0 0 0 0 . 0 . 0 0 0 . 0 . 0 0 0 0 0 0 0 . 
. . . 0 . . . . . . . 1 . . . 1 . . . 1 . . . 1 . . . 0 . 0 . . . 0 . . . 0 . 0 . . . 0 . . . . . 0 . . . 0 . 
. 0 0 0 0 0 . 1 . 1 . 1 . 1 1 1 . 1 1 1 1 1 1 1 1 1 . 0 0 0 . 0 0 0 . 0 0 0 0 0 . 0 0 0 0 0 0 0 . 0 . 0 0 0 . 
. . . 0 . . . 1 . 1 . 1 . . . 1 . . . 1 . 1 . 1 . . . . . 0 . . . 0 . . . . . 0 . . . 0 . . . . . . . . . 0 . 
. 0 0 0 0 0 . 1 1 1 1 1 . 1 1 1 1 1 . 1 . 1 . 1 . 1 . 0 0 0 . 0 0 0 0 0 . 0 0 0 0 0 0 0 . 0 . 0 . 0 . 0 0 0 . 
. 0 . 0 . . . 1 . . . 1 . . . 1 . 1 . . . . . . . 1 . . . 0 . . . 0 . 0 . . . 0 . . . . . 0 . 0 . 0 . . . 0 . 
. 0 . 0 . 1 1 1 1 1 . 1 1 1 . 1 . 1 1 1 1 1 1 1 1 1 1 1 . 0 0 0 . 0 . 0 0 0 . 0 . 0 . 0 . 0 0 0 0 0 0 0 . 0 . 
. 0 . . . 1 . . . . . 1 . . . . . 1 . 1 . 1 . 1 . 1 . . . . . 0 . . . 0 . . . . . 0 . 0 . 0 . . . 0 . . . 0 . 
. 0 0 0 . 1 . 1 . 1 1 1 1 1 . 1 . 1 . 1 . 1 . 1 . 1 1 1 . 0 0 0 0 0 0 0 . 0 . 0 . 0 0 0 0 0 0 0 . 0 0 0 0 0 . 
. 0 . . . 1 . 1 . . . 1 . . . 1 . . . . . . . . . 1 . . . . . 0 . 0 . . . 0 . 0 . 0 . . . 0 . . . 0 . 0 . 0 . 
. 0 0 0 . 1 1 1 . 1 . 1 1 1 1 1 1 1 . 1 1 1 1 1 1 1 . 0 0 0 0 0 . 0 . 0 0 0 0 0 0 0 0 0 . 0 . 3 . 0 . 0 . 0 . 
. 0 . . . . . 1 . 1 . . . . . . . . . . . 1 . 1 . . . . . 0 . 0 . . . . . 0 . . . 0 . . . . . 3 . . . . . . . 
. 0 0 0 0 0 . 1 1 1 . 1 . 1 . 1 . 1 1 1 1 1 . 1 . 0 0 0 0 0 . 0 . 0 . 0 0 0 . 0 . 0 . 3 3 3 3 3 3 3 3 3 3 3 . 
. 0 . 0 . . . . . 1 . 1 . 1 . 1 . . . 1 . . . . . . . 0 . 0 . . . 0 . . . 0 . 0 . . . . . 3 . . . 3 . . . 3 . 
. 0 . 0 0 0 0 0 . 1 1 1 1 1 1 1 1 1 1 1 . 0 . 0 . 0 . 0 . 0 0 0 0 0 . 0 0 0 0 0 . 0 . 3 3 3 . 3 3 3 . 3 . 3 . 
. . . 0 . 0 . . . . . 1 . . . . . . . . . 0 . 0 . 0 . . . . . 0 . . . . . . . 0 . 0 . . . 3 . . . 3 . 3 . . . 
. 0 . 0 . 0 0 0 . 0 . 1 . 0 . 0 . 0 . 0 . 0 0 0 0 0 0 0 . 0 . 0 0 0 0 0 . 0 0 0 0 0 0 0 . 3 . 3 3 3 3 3 . 3 . 
. 0 . . . 0 . . . 0 . . . 0 . 0 . 0 . 0 . 0 . . . 0 . . . 0 . . . 0 . . . . . . . 0 . . . . . . . . . 3 . 3 . 
. 0 . 0 0 0 0 0 0 0 0 0 . 0 0 0 0 0 0 0 0 0 0 0 . 0 0 0 0 0 0 0 . 0 0 0 0 0 . 0 0 0 0 0 . 0 . 0 . 0 . 3 3 3 . 
. 0 . . . 0 . 0 . 0 . . . 0 . . . 0 . 0 . 0 . . . 0 . 0 . 0 . . . . . . . . . . . 0 . . . 0 . 0 . 0 . . . 3 . 
. 0 0 0 . 0 . 0 . 0 0 0 . 0 . 0 . 0 . 0 . 0 . 0 . 0 . 0 . 0 0 0 . 0 . 0 . 0 . 0 0 0 . 0 0 0 0 0 0 0 0 0 . 3 . 
. . . 0 . . . . . 0 . . . 0 . 0 . . . . . . . 0 . . . . . 0 . . . 0 . 0 . 0 . . . 0 . . . 0 . . . 0 . . . 3 . 
. 0 0 0 0 0 . 0 0 0 0 0 . 0 0 0 0 0 . 0 0 0 0 0 0 0 . 0 0 0 0 0 0 0 0 0 0 0 0 0 . 0 0 0 0 0 . 0 0 0 0 0 . 3 . 
. 0 . . . 0 . . . 0 . . . . . 0 . . . 0 . 0 . . . 0 . . . 0 . 0 . 0 . 0 . 0 . . . . . 0 . 0 . . . 0 . . . 3 . 
. 0 . 0 0 0 0 0 0 0 0 0 . 0 0 0 . 0 . 0 . 0 . 0 0 0 . 0 . 0 . 0 . 0 . 0 . 0 0 0 0 0 . 0 . 0 . 0 . 0 0 0 . 3 . 
. 0 . . . 0 . 0 . 0 . . . . . 0 . 0 . . . . . . . 0 . 0 . . . . . . . . . 0 . 0 . . . . . . . 0 . 0 . . . 3 . 
. 0 0 0 . 0 . 0 . 0 . 0 0 0 0 0 0 0 0 0 . 2 . 2 . 0 0 0 . 0 . 0 . 0 0 0 . 0 . 0 0 0 0 0 . 0 0 0 0 0 0 0 . 3 . 
. 0 . . . . . . . . . . . . . . . 0 . . . 2 . 2 . . . 0 . 0 . 0 . 0 . . . . . 0 . 0 . . . . . 0 . . . . . 3 . 
. 0 0 0 . 0 0 0 . 0 . 0 . 0 . 0 . 0 0 0 . 2 2 2 2 2 . 0 0 0 0 0 0 0 . 0 . 0 . 0 . 0 0 0 . 0 0 0 0 0 . 3 . 3 . 
. 0 . . . . . 0 . 0 . 0 . 0 . 0 . 0 . . . 2 . . . . . 0 . . . . . . . 0 . 0 . . . 0 . . . . . 0 . . . 3 . 3 . 
. 0 0 0 . 0 . 0 0 0 0 0 0 0 0 0 0 0 0 0 . 2 2 2 . 0 0 0 . 0 . 0 . 0 0 0 0 0 0 0 0 0 0 0 . 0 . 0 0 0 . 3 3 3 . 
. 0 . . . 0 . 0 . . . 0 . 0 . 0 . 0 . . . 2 . . . 0 . . . 0 . 0 . . . 0 . 0 . 0 . 0 . . . 0 . 0 . . . 3 . . . 
. 0 0 0 0 0 0 0 0 0 . 0 . 0 . 0 . 0 . 2 2 2 2 2 . 0 . 0 0 0 0 0 0 0 0 0 . 0 . 0 . 0 . 0 0 0 0 0 . 3 . 3 3 3 . 
. 0 . 0 . 0 . 0 . . . . . . . . . . . 2 . . . . . 0 . . . 0 . 0 . 0 . 0 . . . . . . . 0 . . . . . 3 . 3 . . . 
. 0 . 0 . 0 . 0 . 2 2 2 2 2 2 2 2 2 2 2 2 2 . 0 0 0 . 0 0 0 . 0 . 0 . 0 . 0 0 0 0 0 0 0 . 0 . 3 3 3 3 3 3 3 . 
. . . . . . . . . 2 . . . 2 . 2 . 2 . 2 . . . 0 . . . . . 0 . . . . . . . 0 . 0 . . . 0 . 0 . . . 3 . . . 3 . 
. 2 . 2 2 2 2 2 2 2 2 2 . 2 . 2 . 2 . 2 . 0 0 0 . 0 0 0 0 0 0 0 . 0 0 0 0 0 . 0 . 0 0 0 0 0 . 3 3 3 3 3 . 3 . 
. 2 . 2 . . . 2 . 2 . . . . . . . . . . . . . 0 . . . 0 . 0 . . . . . . . . . 0 . . . . . 0 . . . 3 . . . 3 . 
. 2 2 2 2 2 . 2 . 2 . 0 . 0 . 0 . 0 0 0 . 0 0 0 0 0 0 0 . 0 . 0 . 0 . 0 . 0 . 0 0 0 . 0 . 0 . 3 3 3 3 3 . 3 . 
. . . 2 . . . . . . . 0 . 0 . 0 . 0 . . . . . 0 . 0 . 0 . . . 0 . 0 . 0 . 0 . . . . . 0 . 0 . . . 3 . . . 3 . 
. 2 . 2 2 2 . 0 0 0 0 0 0 0 0 0 0 0 . 0 0 0 0 0 . 0 . 0 . 0 . 0 0 0 0 0 0 0 0 0 . 0 . 0 0 0 . 3 3 3 3 3 . 3 . 
. 2 . 2 . . . 0 . 0 . 0 . 0 . . . 0 . . . 0 . 0 . . . . . 0 . . . 0 . . . 0 . . . 0 . 0 . . . . . 3 . . . . . 
. 2 2 2 2 2 . 0 . 0 . 0 . 0 . 0 0 0 0 0 0 0 . 0 . 0 0 0 0 0 0 0 . 0 0 0 . 0 0 0 0 0 0 0 0 0 . 3 3 3 . 3 . 3 . 
. 2 . . . . . 0 . . . . . . . . . 0 . 0 . 0 . . . 0 . . . 0 . . . 0 . . . 0 . 0 . 0 . 0 . . . . . 3 . 3 . 3 . 
. 2 2 2 . 0 0 0 0 0 0 0 0 0 0 0 . 0 . 0 . 0 0 0 0 0 0 0 . 0 0 0 0 0 0 0 . 0 . 0 . 0 . 0 . 3 3 3 3 3 3 3 3 3 . 
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
Thread 0 claimed 462 neighbors.
Thread 1 claimed 169 neighbors.
Thread 2 claimed 39 neighbors.
Thread 3 claimed 55 neighbors.
```
