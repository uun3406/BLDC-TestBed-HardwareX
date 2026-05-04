from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

root = Path(__file__).resolve().parents[1]
cur = pd.read_csv(root / 'data/raw/steady_state_current_raw.csv')
spd = pd.read_csv(root / 'data/raw/steady_state_speed_raw.csv')
for df, ylabel, outname in [(cur, 'Current (A)', 'steady_state_current_regenerated.png'), (spd, 'Speed (rpm)', 'steady_state_speed_regenerated.png')]:
    plt.figure(figsize=(7,4))
    for col in df.columns[1:]:
        plt.plot(df['time_s'], df[col], label=col)
    plt.xlabel('Time (s)')
    plt.ylabel(ylabel)
    plt.legend()
    plt.tight_layout()
    out = root / 'manuscript_support/figures' / outname
    out.parent.mkdir(parents=True, exist_ok=True)
    plt.savefig(out, dpi=300)
    print(out)
