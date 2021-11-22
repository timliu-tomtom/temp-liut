
### H-Search ###
| Criterion | selectionCriterion |namedObjectClass | 
| --- | --- | --- |
| A | 0 | 0 COUNTRY |
| B | 9 | 2 ORDER_1 |
| C | 1 | 9 ORDER_8 |
| D | 6 | 10 ORDER_9 |
| E | 17 | 24 NEIGHBORHOOD |


| H-search and reverse| clientlib-common-Address | nk1-reverse-geo |
| --- | --- | --- |
| Country | Country | 
| Prefecture | State | stateName
| Municipality | City | cityName
| Oaza | CityDistrict | districtName
| Chome/aza | CityBlock | localityName
| House number | HouseNumber


nk1-VHCommon-Model-Imp-VH-Proto-SafetyLocationEntry.proto
nk1-VHCommon-Model-Imp-VH-Proto-SafetyLocationProvider.proto ?
### Safety location in VH ###

nk1-Routing-RouteInfo-Api-ICameraProvider.h

../Engines/MapMatching/DrivingAssistance/VehicleHorizonCommon/SafetyLocation/Interface/TomTom/NavKit/VehicleHorizon/SafetyLocation/SafetyLocationData.h
../Engines/MapMatching/DrivingAssistance/Model/Implementation/TomTom/NavKit/VehicleHorizon/Protobuf/PathSafetyLocation.proto
nk1-VHCommon-Proto-Api-Imp-Converter-PathSafetyLocationConverter

### Online routing ###
nk2-trip-onboard -> http request -> NKWorkerService (docker) -> thrift -> NKWorkerEngine (docker, nk1) -> Routing engine (as a lib of NKWorkerEngine)

build NKWorkerService 和 NKWorkerEngine 會產生各自的 docker image (系統須裝docker, 看起來是用/usr/bin/docker)
run-processes-nkw 可以跑 NKWorkerService 和 NKWorkerEngine 在 docker 裡
run docker可以跑起來, 有web demo tool loccalhost:5000 

For debugging, `run-processes-nkw -no-engine` and 自己跑 `nk1/bin/NKWorkerEngine` , 就可以看到NKWorkerEngine的log, breakpoint...

e2e test
run-e2e-test.py (start server)
再用intellij open nk2-e2e-test and run

有VPN的話, ifconfig會看到 mtu xxxx
要把docker-setup script裡面mtu的值改成該值

press ctrl+c only ONCE and wait it gratefully stop (close virtual internet), do not force stop, force stopping may cause virtual network not close properly and impact normal network access.

docker image prune -a (清掉沒在用的docker image)

需裝ant



Tollgate instruction \
HCP3\
  map contains TOLL_ENTRY/TOLL_EXIT, TOLL_GATE_PAYMENT_TYPE, MASK\
  DataAccess implemented in GuidanceDataReader with TollBoothPlaza\
  https://bitbucket.tomtomgroup.com/projects/NAVKIT/repos/dev-geoexpansion/pull-requests/228/overview
  
  RoutingDataPerTile -> TTollBoothPlazasStorage\
  RoutingDataPerTile -> TTollBoothPaymentTypesStorage

  Instruction engine implemented with TollBoothPlaza\
  https://bitbucket.tomtomgroup.com/projects/NAVKIT2/repos/nk2-navigation-instruction-engine/pull-requests/1232/overview

  map does not have tollgate name\
  
Caruso2\
  map contains TOLL_PAYMENT_TYPE, MASK\
  DataAccess implemented with LandGuidanceReader\
  https://bitbucket.tomtomgroup.com/projects/NAVKIT/repos/dev-geoexpansion/pull-requests/53/overview
  https://bitbucket.tomtomgroup.com/projects/NAVKIT/repos/dev-geoexpansion/pull-requests/73/overview

  The implementation in instruction engine with TollBoothPlaza does not work for get payment type\
  Potential solution 
   * Handle [TOLL_PAYMENT_TYPE, MASK] in GuidanceDataReader and stored to TTollBoothPaymentTypesStorage as well\
   * Instruction engine introduce own tollgate struct combine plaza and RoutingData::GetPaymentType(arc)\ 


Tollgate lane guidance


```
Select locationInputId, locationInputString, displayString, criterionA, criterionB, criterionC, criterionD, criterionE
from sliCriterionDTable WHERE languageCode is 112 AND criterionC IN
(
  Select criterionC from sliCriterionDTable WHERE languageCode is 112 AND locationInputString is null
)
```