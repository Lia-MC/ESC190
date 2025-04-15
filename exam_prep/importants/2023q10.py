# Question 10. [10 marks]
# We can use a dictionary to record who is friends with whom by recording the lists of friends in a dictionary.
# For example:
# friends = {"Carl Gauss": ["Isaac Newton", "Gottfried Leibniz", "Charles Babbage"],
# "Gottfried Leibniz": ["Carl Gauss"],
# "Isaac Newton": ["Carl Gauss", "Charles Babbage"],
# "Ada Lovelace": ["Charles Babbage", "Michael Faraday"],
# "Charles Babbage": ["Isaac Newton", "Carl Gauss", "Ada Lovelace"],
# "Michael Faraday": ["Ada Lovelace"] }
# Here, Carl Gauss is friends with Isaac Newton, Gottfried Leibniz, and Charles Babbage. Assume that
# friendships are symmetric, so that if X is friends with Y, then it’s guaranteed that Y is friends with X.
# A friendship chain is a chain of people who are connected by friendship, with no repetitions allowed.
# For example, the following is a friendship chain of length 5:
# Carl Gauss → Isaac Newton → Charles Babbage → Ada Lovelace → Michael Faraday
# Write a function which takes in a dictionary in the format above, and returns the length of the longest
# friendship chain in the data in the dictionary.
# You must not use recursion.

