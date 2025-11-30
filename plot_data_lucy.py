import pandas as pd
import matplotlib.pyplot as plt
import sys

#assign data to vars
df_points = pd.read_csv('output/iteration_6_points.csv')
df_clusters = pd.read_csv('output/iteration_6_clusters.csv')

#pull point data into arrays
x_points = df_points['x']
y_points = df_points['y']
clid_points = df_points['cluster_id']

x_clusters = df_clusters['x']
y_clusters = df_clusters['y']

#scatter plot them
plt.scatter(
    x_points, 
    y_points,
    c=clid_points,
    cmap='tab10',
    s=100
    )

plt.scatter(
    x_clusters,
    y_clusters,
    marker='x',
    s=200,
    c='red',
    label='Cluster Center'
)

#label axis and make a legend
plt.xlabel('x')
plt.ylabel('y')
plt.legend

#save as an image
plt.savefig('iteration_6.png', dpi=150, bbox_inches='tight')