import pandas as pd
import matplotlib.pyplot as plt
import sys

# function to read the data from a csv file

def read_data(csv_file):
    
    df = pd.read_csv(csv_file)
    
    return df

# oooh pretty colors

def plot_colors(data):
    colors = ['#FF6B6B', '#4ECDC4', '#45B7D1', '#FFA07A', '#98D8C8', '#F7DC6F', '#BB8FCE', '#85C1E2', '#F8B739', '#52BE80']
    
    # use explicit Figure and Axes so we can return the Figure object
    fig, ax = plt.subplots(figsize=(10, 8))

    i = 0
    for column in data.columns[1:]:
        # plot only points (no connecting lines)
        ax.scatter(
            data[data.columns[0]],
            data[column],
            color=colors[i % len(colors)],
            s=50,
            label=column,
        )
        i = i + 1

    ax.set_xlabel(data.columns[0])
    ax.set_ylabel('Values')
    
    
    ax.set_title('Data Plots')
    ax.legend()
    
    
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