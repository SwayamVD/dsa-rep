import requests
import base64

API_URL = "https://ce.judge0.com/submissions/?base64_encoded=true&wait=true"

source_code = """
import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Brute-force approach
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] { i, j };
                }
            }
        }
        // Return an empty array if no solution is found
        return new int[] {};
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        int[] result1 = solution.twoSum(nums1, target1);
        System.out.println("Input: nums = " + Arrays.toString(nums1) + ", target = " + target1);
        System.out.println("Output: " + Arrays.toString(result1)); // Expected: [0, 1]

        // Example 2
        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        int[] result2 = solution.twoSum(nums2, target2);
        System.out.println("\nInput: nums = " + Arrays.toString(nums2) + ", target = " + target2);
        System.out.println("Output: " + Arrays.toString(result2)); // Expected: [1, 2]

        // Example 3
        int[] nums3 = {3, 3};
        int target3 = 6;
        int[] result3 = solution.twoSum(nums3, target3);
        System.out.println("\nInput: nums = " + Arrays.toString(nums3) + ", target = " + target3);
        System.out.println("Output: " + Arrays.toString(result3)); // Expected: [0, 1]

        // Example 4
        int[] nums4 = {1, 2, 3, 4, 5};
        int target4 = 10;
        int[] result4 = solution.twoSum(nums4, target4);
        System.out.println("\nInput: nums = " + Arrays.toString(nums4) + ", target = " + target4);
        System.out.println("Output: " + Arrays.toString(result4)); // Expected: []
    }
}

"""
encoded_code = base64.b64encode(source_code.encode()).decode()

payload = {
    "language_id": 62,  # Python 3
    "source_code": encoded_code,
}

response = requests.post(API_URL, json=payload)

if response.status_code == 201 or response.status_code == 200:
    result = response.json()

    # Decode stdout if present
    stdout = result.get("stdout")
    if stdout:
        stdout = base64.b64decode(stdout).decode()

    stderr = result.get("stderr")
    if stderr:
        stderr = base64.b64decode(stderr).decode()

    print("Output:", stdout)
    print("Errors:", stderr)
    print("Compile Output:", result.get("compile_output"))
    print("Status:", result["status"]["description"])
else:
    print("Error:", response.status_code, response.text)
