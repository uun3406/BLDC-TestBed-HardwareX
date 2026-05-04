# Scripts

Python scripts for regenerating processed data and figures from the CSV files.

Recommended environment:

```bash
python -m venv .venv
source .venv/bin/activate  # Windows: .venv\Scripts\activate
pip install pandas matplotlib numpy
```

Run examples:

```bash
python scripts/plot_model_vs_experiment.py
python scripts/plot_steady_state.py
python scripts/plot_dynamic_response.py
python scripts/torque_calibration.py
```
