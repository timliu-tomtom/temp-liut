
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


### ASAN ###

https://jira.tomtomgroup.com/browse/NAV-81770


### Tollgate instruction ###
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





### CLion debug ###
run search-onboard-service-app, (in conan build, specify searchlib:build_type=debug (since artifactory is release, make debug will pull down and re-build))which use searchlib
go to build, find xxx.cmake find searchlib hash code
open .conan/<hash code>/xxx.cpp and set break point






```
/code/navigation-instruction-engine/src/situation_handlers/../lane_guidance/lane_guidance_builder.hpp:23:10: error: 'TomTom/NavKit/MapDataAccess/Map/Map.h' file not found [clang-diagnostic-error]
#include <TomTom/NavKit/MapDataAccess/Map/Map.h>

clang-tidy-10  -p=./build ./navigation-instruction-engine/src/get_full_instruction_list_specialization.hpp
```


```
  AddressProcessor::Populate()
      InitializeAddressParts();
      PopulateAddressFromAttribute(address_builder);
      PopulateAddressFromClosestRoad(*location_, address_builder);
             PopulateAddressFromAdminAreaNames()
                    address_builder.WithMunicipalitySubdivisionName(order9);
                    address_builder.WithCityName(std::move(order9));
                    address_builder.WithMunicipalityName("");
         
      FinalizeAddressParts(address_builder);

      <feature type="nt_container" index="95">
                                <linkId type="uint16_t">293</linkId>
                            </feature>
```

                            https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D2410%26updateRegionId%3D2700%26namedObjectId%3D29413%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999479492&lat=22.6085&lon=120.2738&layers=FFFBFFFFFFF000FFFTTF0000TT&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://stackoverflow.com/questions/38950802/how-to-display-line-numbers-in-side-by-side-diff-in-unix
```
sdiff -l ../../old.txt ../../new.txt | cat -n | grep -v -e '($'
```
            
207246 70276 麥當勞-府中

新光

https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D13527035.739219%26lat%3D2881354.1438284%26scale%3D1821.844205863098%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.291537549196&lat=25.04565&lon=121.51496&layers=FFFBFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D13527981.353484%26lat%3D2881414.6149003%26scale%3D1821.844205863098%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.291537549196&lat=25.04585&lon=121.52427&layers=FFFBFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

https://nds.tomtomgroup.com/webviewer/43840/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D13527377.884602%26lat%3D2881367.6840997%26scale%3D1821.844205863098%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18.291537549196&lat=25.04558&lon=121.51868&layers=FFFBFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


catId 273

```
SELECT l.poiId, l.catId, r.isBrand from poiTable l INNER JOIN poiCategoryTable r where l.catId == r.isBrand AND r.isBrand is 1
```

https://nds.tomtomgroup.com/webviewer/43927/?action=FeatureInfo%3Flang%3DGBR_eng_Latn%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26mode%3DNEAREST_POI%26lon%3D1484169.1182216%26lat%3D6892336.6371566%26scale%3D2132.7295838497844%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=18&lat=52.50723&lon=13.3344&layers=FFFBFFFFFFFT000FFFTTF0000TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=GBR_eng_Latn&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true



充電スタンド(急速充電) (1901)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3D*_*_Jpan%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D37537140%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999516927&lat=33.60127&lon=133.61461&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=*_*_Jpan&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true


充電スタンド(一般充電) (1902)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3D*_*_Jpan%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D17278780%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999516927&lat=32.93867&lon=130.55902&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=*_*_Jpan&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

充電スタンド(一般充電コンセント型) (1903)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3D*_*_Jpan%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D86511060%26panTo%3Dtrue%26zoomTo%3Dtrue%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=17.999999999516927&lat=34.6463&lon=135.51076&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=*_*_Jpan&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true

充電スタンド (40916)

https://nds.tomtomgroup.com/webviewer/41307/?action=FeatureInfo%3Flang%3DNULL%26poiCategoryCollectionId%3D0%26iconCollectionId%3D0%26productId%3D0%26updateRegionId%3D4456%26buildingBlockId%3D4%26poiId%3D43834580%26disputantId%3D0%26theme%3DDEFAULT%26routingService%3D0%26routeType%3DTIME_WITH_PENALTY%26vehicleType%3DPERSONAL_CAR%26labeling%3Dtrue%26icons%3Dtrue&zoom=16.999999999516927&lat=34.0422&lon=131.9126&layers=FFFBFFFFFF0FFTTF00TT&&poiCategoryCollectionId=0&iconCollectionId=0&disputantId=0&lang=NULL&theme=DEFAULT&routingService=0&routeType=TIME_WITH_PENALTY&vehicleType=PERSONAL_CAR&labeling=true&icons=true
