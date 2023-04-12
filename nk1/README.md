nk1

https://fs-eu.tomtomgroup.com/adfs/ls/IdpInitiatedSignOn.aspx
https://fs-tt.tomtomgroup.com/adfs/ls/IdpInitiatedSignOn.aspx

https://signin.aws.amazon.com/saml
https://ap-northeast-2.console.aws.amazon.com/ec2/home?region=ap-northeast-2#Home:
https://myapplications.microsoft.com/


### nk1 training ###
DataAccess Ring Example \
Search - part 2 \
DataAccess 2nd section \
Framework 2nd section - Reflection \
Instruction to EV https://demo.prod.tt-nkw.trafficmanager.net/ \
Search - part1 \
Vehicle Horizon \
Guidance

https://tomtominternational-my.sharepoint.com/:f:/g/personal/tim_liu_tomtom_com/EoJPf5rCU19Bms8B87YKfv0BRYzfjwqIqA6Tmpk2SO6zgg?e=GOmo1q


NK1 DataAccess_ flexible attribute reader - session 1 \
https://tomtominternational-my.sharepoint.com/personal/shawn_chen_tomtom_com/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Fshawn%5Fchen%5Ftomtom%5Fcom%2FDocuments%2FRecordings%2FNK1%20DataAccess%5F%20flexible%20attribute%20reader%2D20210520%5F141118%2DMeeting%20Recording%2Emp4&parent=%2Fpersonal%2Fshawn%5Fchen%5Ftomtom%5Fcom%2FDocuments%2FRecordings&originalPath=aHR0cHM6Ly90b210b21pbnRlcm5hdGlvbmFsLW15LnNoYXJlcG9pbnQuY29tLzp2Oi9nL3BlcnNvbmFsL3NoYXduX2NoZW5fdG9tdG9tX2NvbS9FUkZ3Q2NJNFRWSktwbnkxcmJJdXlXb0JVTnAtSmg2dDlweVp4bjRWaTlfUHRnP3J0aW1lPWQwMkxjUmdnMlVn


DataAccess flexible attribute reader - session 2 \
https://tomtominternational-my.sharepoint.com/personal/shawn_chen_tomtom_com/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Fshawn%5Fchen%5Ftomtom%5Fcom%2FDocuments%2FRecordings%2FNK1%20DataAccess%5F%20flexible%20attribute%20reader%20Part2%2D20210526%5F140227%2DMeeting%20Recording%2Emp4&parent=%2Fpersonal%2Fshawn%5Fchen%5Ftomtom%5Fcom%2FDocuments%2FRecordings&originalPath=aHR0cHM6Ly90b210b21pbnRlcm5hdGlvbmFsLW15LnNoYXJlcG9pbnQuY29tLzp2Oi9nL3BlcnNvbmFsL3NoYXduX2NoZW5fdG9tdG9tX2NvbS9FY0RHWko0SWV2QkFvMm5Qc3phOWsxb0JPQVVxN0kxcnhhZVBxVDRERG1vbUNRP3J0aW1lPWxKcnRaWElsMlVn
GeoLine handles more than RoutingLink \
CAttributeOfDirectedGeoLine handles more than CAttributeOfUndirectedGeoLine \
Most case could use CAttributeOfDirectedGeoLine to cover CAttributeOfDirectedRoutingLink, CAttributeOfDirectedGeoLine, CAttributeOfUndirectedGeoLine \
KDistinguishUndirected -> change which and how many callback is called


Search \
Q: If user types "TómTóm", how do we match it to "TomTom", is it also handled by fuzzy search ?\
​A: No, diacritics are irrelevant (at least for our maps), also case is irrelevant\
​Q: Thanks, and how about numbers, e.g. user type "nine nine coffee", could it find "99 coffee restaurant"\
​A: Probably not. I am preparing a presentation about everything related to strings (tokenization, character change rules, token change rules). But something like 5th ave <=> fifth avenue could work (via NDS token change rules)\
Q:\
    I have 2 more questions, \
    For page size parameter in iFreeTextSearch, does Search engine just return 1 page each time? and when application query next page, does it do a full query again without caching?\
	For online search, does SEARCHPU online APIs also use NKW as backend? (that is, still do a onbard NavKit search on remote instance, and simply parameterize the result to return ). 

​A:\
    At 1) Yes, search returns one page of results at a time. Next page of results will be returned when requested. But with current search engine, all results are determined only once (steps 1 to 3 on slide 13), only the last 2 steps (post processing per page, sending results), are done for each page.\
    At 2) No.

Routing\
https://web.microsoftstream.com/video/32675e70-c4ea-420e-8269-55c05fe13fc3\
Regarding difference between RouteReconstruction and RouteReassessment:\
RouteReconstruction happens at each NavKit restart and really just reconstructs a route object from the trip/route that was last saved to the TLV file, and it requires the exact same map that the route was stored from (all arc IDs must be identical). \
RouteReassessment: If there was a map update, route reconstruction will fail because some or all arcs are different. This means a new route is calculated that most closely follows the old path.


TTI\
https://tomtominternational-my.sharepoint.com/:v:/r/personal/andrii_boiko_tomtom_com/Documents/Recordings/Introduction%20to%20Nk2UI_%20Navigation-20210917_093145-Meeting%20Recording.mp4?csf=1&web=1&e=MVdDvS


DataAccess api supports multiple direction (not sure whether it really read multiple direction from map)
InstructionBuilderUtils.ToLaneMarking, at least here only convert to one direction