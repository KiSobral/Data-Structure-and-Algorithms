class AdjNode:
    def __init__(self, data):
        self.node = data
        self.next = None


class Graph:
    def __init__(self, nodes):
        self.nodes = nodes
        self.graph = [None] * self.nodes

    def add_edge(self, begin, dest):
        node = AdjNode(dest)
        node.next = self.graph[begin]
        self.graph[begin] = node

        node = AdjNode(begin)
        node.next = self.graph[dest]
        self.graph[dest] = node

    def print_graph(self):
        for i in range(self.nodes):
            print("Adjacency list of node {}\n head".format(i), end="")
            temp = self.graph[i]
            while temp:
                print(" -> {}".format(temp.node), end="")
                temp = temp.next
            print(" \n")
