from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

root = Path(__file__).resolve().parents[1]
df = pd.read_csv(root / 'data/processed/dynamic_response_processed.csv')
plots = [('current_A', 'Current (A)'), ('speed_rpm', 'Speed (rpm)'), ('torque_Nm', 'Torque (N m)')]
for col, ylabel in plots:
    plt.figure(figsize=(7,4))
    plt.plot(df['time_s'], df[col])
    plt.xlabel('Time (s)')
    plt.ylabel(ylabel)
    plt.title(f'Dynamic load-step response: {ylabel}')
    plt.tight_layout()
    out = root / 'manuscript_support/figures' / f'dynamic_{col}_regenerated.png'
    out.parent.mkdir(parents=True, exist_ok=True)
    plt.savefig(out, dpi=300)
    print(out)
