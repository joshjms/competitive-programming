import subprocess

for i in range(1001):
    result_1 = subprocess.run(['sh', '-c', f'echo {i} | ./b'], capture_output=True, text=True)
    result_2 = subprocess.run(['sh', '-c', f'echo {i} | ./b2'], capture_output=True, text=True)
    
    if result_1.stdout != result_2.stdout:
        print(f"Discrepancy found for input {i}:")
        print("Output of ./b:")
        print(result_1.stdout.strip())
        print("Output of ./b2:")
        print(result_2.stdout.strip())
