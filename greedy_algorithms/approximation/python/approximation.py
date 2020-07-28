# A set of states to the radio sign reach
states_to_reach = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])

# A dictionary to storage the stations and its respective states
stations = {}
stations["k-one"] = set(["id", "nv", "ut"])
stations["k-two"] = set(["wa", "id", "mt"])
stations["k-three"] = set(["or", "nv", "ca"])
stations["k-four"] = set(["nv", "ut"])
stations["k-five"] = set(["ca", "az"])

# A dictionary containing all the stations needed to reach all states
final_stations = set()

while states_to_reach:
    best_station = None
    reached_states = set()

    for station, states_per_station in stations.items():
        reached = states_to_reach & states_per_station

        if len(reached) > len(reached_states):
            best_station = station
            reached_states = reached

        final_stations.add(best_station)
        states_to_reach -= reached_states

final_stations -= set([None])
print(final_stations)
