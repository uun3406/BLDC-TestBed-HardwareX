from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

root = Path(__file__).resolve().parents[1]
df = pd.read_csv(root / 'data/processed/model_vs_experiment.csv')
rmse = ((df['error_rpm'] ** 2).mean()) ** 0.5
plt.figure(figsize=(7,4))
plt.plot(df['time_s'], df['model_speed_rpm'], label='Model')
plt.plot(df['time_s'], df['experimental_speed_rpm'], label='Experiment', linestyle='--')
plt.xlabel('Time (s)')
plt.ylabel('Speed (rpm)')
plt.title(f'Model vs Experimental Speed Response, RMSE = {rmse:.1f} rpm')
plt.legend()
plt.tight_layout()
out = root / 'manuscript_support/figures/model_vs_experiment_regenerated.png'
out.parent.mkdir(parents=True, exist_ok=True)
plt.savefig(out, dpi=300)
print(out)
