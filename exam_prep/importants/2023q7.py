# We would like to be able to sort lists of integers by their average. For example, if I have the following lists
# 1, 3 # average:2
# 6, 4, 5 # average: 5
# 20, -20 # average: 0
# I would like to be able sort the lists as follows:
# 20, -20 # average: 0
# 1, 3 # average:2
# 6, 4, 5 # average: 5
# We would like to be able to use the following:
# my_lists = [MyList([1, 3]), MyList([5, 4, 6]), MyList([20, -20])]
# print(sorted(my_lists)) # prints out [[-20, 20], [1, 3], [6, 4, 5]]
# Write Python 3 code so that the two lines above run as specified in the comment, for any input lists of
# integers. Assume all lists are non-empty