import pandas as pd
import matplotlib.pyplot as plt

csv = pd.read_csv("./results/seagullrun_56618.csv")

par = csv[csv["algo"] == "parallel"]
X = par["threads"].values
y = par["time_ms"].values
seq_time = csv[csv["algo"] == "sequential"]["time_ms"].values[0]
speedup = seq_time / y
plt.figure()
seq_time = csv[csv["algo"] == "sequential"]["time_ms"].values[0]
plt.axhline(seq_time, linestyle=':', color='gray', label='sequential')

std_time = csv[csv["algo"] == "std"]["time_ms"].values[0]
plt.axhline(std_time, linestyle='--', color='gray', label='std::sort')
plt.plot(X, speedup, marker='o', label='measured (seagull)')
plt.plot(X, X, linestyle='--', color='black', label='ideal (speedup = threads)')
plt.xlabel("threads")
plt.ylabel("speedup vs sequential")
plt.ylabel("time (ms)")
plt.xscale("log", base=2)
plt.yscale("log", base=2)
plt.xticks(X, X)
plt.yticks(X, X)
plt.legend()
plt.savefig("speedup.png")

plt.figure()
plt.plot(X, y, marker='o', label='parallel (seagull)')
plt.xlabel("threads")

plt.legend()
plt.savefig("time_vs_threads.png")

plt.show()            
