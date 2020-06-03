# PHILOSOPHERS
## DESIGN
Philosophers is a solution to the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), an example problem created by Edsger Djikstra (refined by Tony Hoare) to illustrate problems in managing resource access among concurrent processes. Our solution utilizes an asymmtrical solution: resources have a partial ordering imposed on them, and even numbered philosophers acquire their lower ordered mutex before the higher ordered mutex, while the odd numbered philosophers acquire their mutexes in the reverse order. Mutexes are released higher first, then lower. While rarely running the risk of resource starvation, this solution provides philosophers relatively equal access to resources with a limited number of synchronization primitives (*pthread_mutex_lock*, *pthread_mutex_unlock*, *pthread_create*, and *pthread_join*). 

## REQUIREMENTS
Our program assumes that *make*, *ncurses* and *pthreads* are both installed and available on the system.

## USAGE

The *eating*, *resting*, and  *feeding* times of the philosopers are controlled by the macros `TIME_EAT`, `TIME_REST`, `TIME_THINK` inside `includes/philo.h`. Altering these values will change the behavior of the philosophers. 
```
# Compile the program
$ make
# Execution
$ ./philo
```

## Resources
### Dining Philosophers Problem
- https://cran.r-project.org/web/packages/simmer/vignettes/simmer-08-philosophers.html
- https://en.wikipedia.org/wiki/Dining_philosophers_problem
- http://howardhinnant.github.io/dining_philosophers.html
- http://web.eecs.utk.edu/~mbeck/classes/cs560/560/notes/Dphil/lecture.html
- https://www.cs.utexas.edu/users/EWD/ewd03xx/EWD310.PDF
### Thread Programming Tools
- https://valgrind.org/docs/manual/hg-manual.html
- https://valgrind.org/docs/manual/drd-manual.html
### Threading Resources
- The Linux Programming Interface: Chapters 29-33
- Advanced Programming in the Unix Environment: Chapters 11-12

## NB
Project done with Travis Matthews.
