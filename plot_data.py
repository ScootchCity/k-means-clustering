# this is slop

import pandas as pd
import matplotlib.pyplot as plt
import sys

# function to read the data from a csv file

def read_data(csv_file):
    
    df = pd.read_csv(csv_file)
    
    return df

# oooh pretty colors

def plot_colors(data):
    colors = ['#FF6B6B', '#4ECDC4']

    # use explicit Figure and Axes so we can return the Figure object
    fig, ax = plt.subplots(figsize=(10, 8))

    cols = list(data.columns)
    cols_lower = [c.lower() for c in cols]

    # If columns named 'x' and 'y' exist (case-insensitive), plot x vs y
    if 'x' in cols_lower and 'y' in cols_lower:
        xi = cols_lower.index('x')
        yi = cols_lower.index('y')
        x_col = cols[xi]
        y_col = cols[yi]
        ax.scatter(data[x_col], data[y_col], color=colors[0], s=50, label=y_col)
        ax.set_xlabel(x_col)
        ax.set_ylabel(y_col)
        ax.legend()
    else:
        # fallback: use first column as x and plot each other column as y
        x_col = cols[0]
        i = 0
        for column in cols[1:]:
            ax.scatter(
                data[x_col],
                data[column],
                color=colors[i % len(colors)],
                s=50,
                label=column,
            )
            i = i + 1
        ax.set_xlabel(x_col)
        ax.set_ylabel('Values')
        ax.legend()

    ax.set_title('Data Plots')
    ax.grid(True)

    return fig


def save_plot(figure, filename='cluster_plot.png'):    
    figure.savefig(filename, dpi=150, bbox_inches='tight')



def visualize_data(csv_file, output_file='data_plot.png'):
    
    data = read_data(csv_file)
    plot_figure = plot_colors(data)
    save_plot(plot_figure, output_file)



csv_file = sys.argv[1]
data = read_data(csv_file)
plot_figure = plot_colors(data)
    
# plt.show()
save_plot(plot_figure, 'data_plot.png')    
