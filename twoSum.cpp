	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <iterator>

	class BruteForceSolution 
	{
	public:
	    std::vector<int> twoSum(std::vector<int>& nums, int target) {
	        std::vector<int> answer;
	        int escape(0);
	        for(int i=0; i != nums.size()-1; i++)
	        {
	            for(int j=nums.size()-1; j != i; j--)
	            {
	                if(nums[i] + nums[j] == target)
	                {
	                    answer.push_back(i);
	                    answer.push_back(j);
	                    escape = 1;
	                    break;
	                }
	                    
	            }
	            if(escape == 1)
	                break;
	        }
	        return answer;
	    }
	};
	
	class OptimumSolution 
	{
	public:
	    std::vector<int> twoSum(std::vector<int>& nums, int target) {
	        std::vector<int> answer;
	        int hold;
	        int escape(0);
	        for(int i=0; i < nums.size()-1; i++)
	        {
	        	hold = target - nums[i];
	        	std::vector<int>::iterator it = std::find(nums.begin()+i+1, nums.end(),hold);
	            if( it != nums.end() )
	            {
	            	int index = std::distance(nums.begin(), it);
	            	answer.push_back(i);
					answer.push_back(index);
					escape = 1;
				}
				if(escape == 1)
				{
					break;
				}
	        }
	        return answer;
	    }
	};
	
	
	int main()
	{
		int target = 0;
		std::vector<int> test = {3,2,7,11,29,33,4};
		
		target = 6;
		OptimumSolution verify;
		std::vector<int> output = verify.twoSum(test,target);
		
		for(int i=0; i < 2; i++)
		{
			std::cout << output[i] << '\n';
		}
		
		return 0;		
	}
