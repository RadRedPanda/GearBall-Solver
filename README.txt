To run it run the "runme.exe"

For the search algorithm I used a vector of Gearballs for the fringe, and sorted it each time something was inserted with one iteration of bubble sort.

For the heuristic, I used two numbers
	The number of faces / 24
	The number of gears out of rotation / 4
and took the max of the two, and rounded it up, using that as my heuristic.

I learned that without a good heuristic, A* won't run very well. There were a few things I could have done to optimize the code, but it would have been negligible compared to the exponential increase in time due to the bad heuristic.