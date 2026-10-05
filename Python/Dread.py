import pandas as pd
import tkinter as tk
from tkinter import filedialog, messagebox


def dread_score(row):
    category = str(row["Category"]).lower()
    title = str(row["Title"]).lower()
    description = str(row["Description"]).lower()

    # Default scores
    damage = 5
    reproducibility = 5
    exploitability = 5
    affected_users = 5
    discoverability = 5

    # STRIDE-based baseline scoring
    if "spoofing" in category:
        damage = 8
        reproducibility = 7
        exploitability = 6
        affected_users = 8
        discoverability = 7

    elif "tampering" in category:
        damage = 8
        reproducibility = 7
        exploitability = 6
        affected_users = 8
        discoverability = 7

    elif "repudiation" in category:
        damage = 5
        reproducibility = 7
        exploitability = 6
        affected_users = 6
        discoverability = 7

    elif "information disclosure" in category:
        damage = 8
        reproducibility = 7
        exploitability = 6
        affected_users = 8
        discoverability = 7

    elif "denial of service" in category:
        damage = 7
        reproducibility = 8
        exploitability = 6
        affected_users = 8
        discoverability = 7

    elif "elevation of privilege" in category:
        damage = 10
        reproducibility = 7
        exploitability = 6
        affected_users = 9
        discoverability = 7

    # Refine scores for particularly serious threats
    if "remote code execution" in title or "remote code execution" in description:
        damage = 10
        exploitability = 7
        affected_users = 9

    if "access control" in title:
        damage = 8
        exploitability = 6
        affected_users = 8

    if "sniffing" in title:
        damage = 8
        exploitability = 6
        affected_users = 8

    if "crash" in title or "stop" in title:
        damage = 7
        reproducibility = 8

    if "inaccessible" in title or "interrupted" in title:
        damage = 7
        reproducibility = 8

    # Calculate DREAD average
    score = (
        damage
        + reproducibility
        + exploitability
        + affected_users
        + discoverability
    ) / 5

    if score >= 7:
        risk = "High"
    elif score >= 4:
        risk = "Medium"
    else:
        risk = "Low"

    return pd.Series([
        damage,
        reproducibility,
        exploitability,
        affected_users,
        discoverability,
        round(score, 2),
        risk
    ])


def main():
    root = tk.Tk()
    root.withdraw()

    input_file = filedialog.askopenfilename(
        title="Select Microsoft Threat Modeling Tool CSV",
        filetypes=[("CSV files", "*.csv")]
    )

    if not input_file:
        return

    try:
        df = pd.read_csv(input_file)

        required_columns = [
            "Title",
            "Category",
            "Description"
        ]

        missing = [
            col for col in required_columns
            if col not in df.columns
        ]

        if missing:
            messagebox.showerror(
                "Invalid CSV",
                "Missing columns:\n" + "\n".join(missing)
            )
            return

        df[
            [
                "Damage",
                "Reproducibility",
                "Exploitability",
                "Affected Users",
                "Discoverability",
                "DREAD Score",
                "Risk Level"
            ]
        ] = df.apply(dread_score, axis=1)

        # Sort highest risk first
        df = df.sort_values(
            by="DREAD Score",
            ascending=False
        )

        output_file = filedialog.asksaveasfilename(
            title="Save DREAD Analysis",
            defaultextension=".csv",
            filetypes=[("CSV files", "*.csv")]
        )

        if not output_file:
            return

        df.to_csv(
            output_file,
            index=False
        )

        messagebox.showinfo(
            "DREAD Analysis Complete",
            f"Analysis completed successfully.\n\n"
            f"Total threats: {len(df)}\n"
            f"Output saved to:\n{output_file}"
        )

    except Exception as e:
        messagebox.showerror(
            "Error",
            f"Something went wrong:\n\n{e}"
        )


if __name__ == "__main__":
    main()