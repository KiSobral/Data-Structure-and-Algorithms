graph = {}
costs = {}
parents = {}
processed_items = []


def set_vars():
    infinity = float("inf")

    # graph settings
    graph["start"] = {"a": 6, "b": 2}
    graph["a"] = {"end": 1}
    graph["b"] = {"a": 3, "end": 5}
    graph["end"] = {}

    # costs settings
    costs["a"] = 6
    costs["b"] = 2
    costs["end"] = infinity

    # parents settings
    parents["a"] = "start"
    parents["b"] = "start"
    parents["end"] = None


def find_cheapest_cost_node():
    cheapest_cost = float("inf")
    cheapest_node = None

    for node, value in costs.items():
        if value < cheapest_cost and node not in processed_items:
            cheapest_cost = value
            cheapest_node = node

    return cheapest_node


def dijkstra():
    node = find_cheapest_cost_node()
    while node is not None:
        cost = costs[node]
        neighbors = graph[node]

        for neighbor, value in neighbors.items():
            new_cost = cost + value
            if new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                parents[neighbor] = node

        processed_items.append(node)
        node = find_cheapest_cost_node()


if __name__ == "__main__":
    set_vars()
    dijkstra()
    print(parents)
