from pathlib import Path
import pandas as pd

root = Path(__file__).resolve().parents[1]
df = pd.read_csv(root / 'data/raw/loadcell_calibration_raw.csv')
df = df[df['adc_counts'] > 0].copy()
df['calibration_factor_Nm_per_count'] = df['applied_torque_Nm'] / df['adc_counts']
print(df)
out = root / 'data/processed/torque_calibration_processed.csv'
df.to_csv(out, index=False)
print('Saved:', out)
