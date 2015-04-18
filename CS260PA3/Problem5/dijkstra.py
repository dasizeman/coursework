nodes = ('A', 'B', 'C', 'D', 'E', 'F')
distances = {
    'A': {'B': 4, 'C': 1, 'D': 5, 'E': 8, 'F': 10},
    'B': {'C': 2},
    'C': {'B': 2},
    'D': {'E': 2},
    'E': {'F': 1},
    'F': {'E': 1, 'A':10}
}

unvisitedList = {node: None for node in nodes} #using None as +inf
visitedList = {}
current = 'A'
currentDistance = 0
unvisitedList[current] = currentDistance

while True:
    for neighbour, distance in distances[current].items():
        if neighbour not in unvisitedList: continue
        newDistance = currentDistance + distance
        if unvisitedList[neighbour] is None or unvisitedList[neighbour] > newDistance:
            unvisitedList[neighbour] = newDistance
    visitedList[current] = currentDistance
    del unvisitedList[current]
    if not unvisitedList: break
    nextPossible = [node for node in unvisitedList.items() if node[1]]
    current, currentDistance = sorted(nextPossible, key = lambda x: x[1])[0]

print(visitedList)
