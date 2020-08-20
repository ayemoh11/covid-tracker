# covid-tracker

Each graph node represents an individual in a specific region. 
It stores the person’s unique identifier as a string (to protect their privacy), 
person’s first name as a string, if they tested positive for the virus as a Boolean, 
and the most‐recent testing date as a string.

Each graph edge is undirected. It represents the most recent contact event between two individuals,
and it stores the number of days since the contact occurred as a non‐negative integer  
along  with  the  reported  contact location as a string (e.g., restaurant, park). 
The value of 0 indicates that the contact occurred on the date when the event was reported, 
1  indicates  that  the  contact occurred on the previous date, and so on.  If there is no 
edge between two people, then they  made  no  contact  that  was  reported. 

Functions: 
- Counts virus-positive contacts
The function will traverse through the graph starting at the person specified by person_id. 
It will then count other distinct individuals who tested positive for the virus who are 
directly or indirectly connected to the starting individual. If the starting individual 
also tested positive, the function will not include that person in the count. If no such 
individuals exists, the function will return 0.

- Find largest cluster with multiple virus-positive contacts
The function will traverse through the people in the graph. It will then count how many other
distinct people are connected to the starting individual and if there are at least two 
individuals in a cluster who tested positive. If no such cluster exists, the function 
will return ‐1. If multiple clusters exist that contain at least two virus‐positive contacts, 
then the function will return the maximum size of any such cluste
