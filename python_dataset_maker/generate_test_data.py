from sklearn.datasets import make_blobs
import pandas as pd

#===== VARIABLES =====
n_samples = 5000        #number of data points
n_centers = 10          #number of cluster centers (k)
cluster_std = 20      #standard deviation (lower = tighter clusters)
center_box = (-100, 100) #range where cluster centers can be placed (min, max)
output_file = '../data/test_data_large.csv' #name of set file
seed = None              #random seed for (can reproduce sets)
#=====================

X, y = make_blobs(
    n_samples=n_samples,
    centers=n_centers,
    cluster_std=cluster_std,
    center_box=center_box,
    random_state=seed
)

pd.DataFrame(X, columns=['x', 'y']).to_csv(output_file, index=False)

print(f"Generated {n_samples} points with {n_centers} clusters (std={cluster_std})")
print(f"Saved to: {output_file}")