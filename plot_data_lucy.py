import pandas as pd
import matplotlib.pyplot as plt
import glob

#put pattern matched filenames into arrays
files_points = glob.glob('output/iteration_*_points.csv')
files_clusters = glob.glob('output/iteration_*_clusters.csv')

#sort filenames (so points and clusters are matched)
files_points.sort()
files_clusters.sort()

i = 0

#loop over all the iterations
for filename_points in files_points:
    #get the matching clusters filename
    filename_clusters = files_clusters[i]

    #assign data to vars
    df_points = pd.read_csv(filename_points)
    df_clusters = pd.read_csv(filename_clusters)

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
        label='Cluster Center',
        linewidths=2
    )

    #label axis and make a legend
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend
    plt.title('k-Means Visualization')

    #save as an image
    plt.savefig('output/images/iteration_' + str(i) + '.png', dpi=150, bbox_inches='tight')
    
    #clear it!
    plt.clf()
    i+=1