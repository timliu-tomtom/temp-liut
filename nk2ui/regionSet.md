        mapManagementComponentApi.observeRegions()
            .onEach { regions -> regions.forEach { printRegions("=", it) } }
            .launchIn(viewModelScope)

    private fun printRegions(prefix: String, mapRegion: MapRegion) {
        logger.error { "TTDebug, region $prefix ${mapRegion.name} shared ${mapRegion.isShared} ${mapRegion.state} " }
        mapRegion.children.forEach { printRegions("$prefix=", it) }
    }

// bundled
2023-01-31 16:05:03.740  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, Installed region
2023-01-31 16:05:03.755  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = North America shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == United States of America shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Alabama shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Alabama North shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Alabama South shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Alaska shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Alaska shared false NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.756  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Arizona shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Arizona shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Arkansas shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Arkansas shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === California shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== California North shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== California Sacramento shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== California San Jose shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== California Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.757  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== California San Francisco shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== California South shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== California Inland Empire shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== California Orange and San Diego shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Los Angeles shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Colorado shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Colorado East shared false NOT_INSTALLED 
2023-01-31 16:05:03.758  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Colorado West shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Connecticut shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Connecticut shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Delaware shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Delaware shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === District of Columbia shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== District of Columbia shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Florida shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Florida North shared false NOT_INSTALLED 
2023-01-31 16:05:03.759  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Florida North shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Florida Orlando shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Florida South shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Florida Middle shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Florida South shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Georgia shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Georgia shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Atlanta shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Idaho shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Idaho shared false NOT_INSTALLED 
2023-01-31 16:05:03.760  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Illinois shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Illinois North shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Illinois South shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Saint Louis shared true NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Chicago shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Indiana shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Indiana South shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Indiana North shared false NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Louisville & Cincinnati shared true NOT_INSTALLED 
2023-01-31 16:05:03.761  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Iowa shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Iowa shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kansas shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Kansas shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Kansas City shared true NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kentucky shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Louisville & Cincinnati shared true NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Kentucky shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Louisiana shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Louisiana shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Maine shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Maine shared false NOT_INSTALLED 
2023-01-31 16:05:03.762  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Maryland shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Maryland shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Massachusetts shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Massachusetts shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Michigan shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Michigan shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Michigan Detroit shared false NOT_INSTALLED 
2023-01-31 16:05:03.763  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Minnesota shared false NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Minnesota North shared false NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Minnesota South shared false NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mississippi shared false NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mississippi shared false NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Missouri shared false NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Saint Louis shared true NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Kansas City shared true NOT_INSTALLED 
2023-01-31 16:05:03.764  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Missouri shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Montana shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Montana shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Nebraska shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Nebraska shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Nevada shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Nevada shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === New Hampshire shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New Hampshire shared false NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.765  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === New Jersey shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New Jersey North shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New Jersey South shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === New Mexico shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New Mexico shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === New York shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New York East shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New York West shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New York City shared false NOT_INSTALLED 
2023-01-31 16:05:03.766  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Long Island New York shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North Carolina shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== North Carolina Charlotte shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== North Carolina Coastal shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North Dakota shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== North Dakota shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ohio shared false NOT_INSTALLED 
2023-01-31 16:05:03.767  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Louisville & Cincinnati shared true NOT_INSTALLED 
2023-01-31 16:05:03.768  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ohio North shared false NOT_INSTALLED 
2023-01-31 16:05:03.769  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ohio South shared false NOT_INSTALLED 
2023-01-31 16:05:03.769  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Oklahoma shared false NOT_INSTALLED 
2023-01-31 16:05:03.769  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Oklahoma shared false NOT_INSTALLED 
2023-01-31 16:05:03.769  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Oregon shared false NOT_INSTALLED 
2023-01-31 16:05:03.769  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Oregon shared false NOT_INSTALLED 
2023-01-31 16:05:03.769  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Pennsylvania shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Pennsylvania Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Pennsylvania East shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Pennsylvania West shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Rhode Island shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Rhode Island shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Carolina shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== South Carolina shared false NOT_INSTALLED 
2023-01-31 16:05:03.770  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Dakota shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== South Dakota shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Tennessee shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Tennessee Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Tennessee East shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Tennessee West shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Texas shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Texas North shared false NOT_INSTALLED 
2023-01-31 16:05:03.771  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Texas East shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Texas West shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Dallas shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Texas South shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Texas Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Texas Houston shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ===== Texas South shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Utah shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Utah shared false NOT_INSTALLED 
2023-01-31 16:05:03.772  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Vermont shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Vermont shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Virginia shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Virginia East shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Virginia West shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Washington shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Washington East shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Washington West shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === West Virginia shared false NOT_INSTALLED 
2023-01-31 16:05:03.773  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== West Virginia shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Wisconsin shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Wisconsin North shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Wisconsin South shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Wyoming shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Wyoming shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Outlying Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Outlying Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Puerto Rico, Virgin Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Puerto Rico & Virgin Island shared false NOT_INSTALLED 
2023-01-31 16:05:03.774  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Canada shared false NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Atlantic Canada shared false NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Atlantic Canada shared false NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Northern Canada shared false NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Northern Canada shared false NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Alberta shared false NOT_INSTALLED 
2023-01-31 16:05:03.775  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Alberta shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === British Columbia shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== British Columbia shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Arctic (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Manitoba shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Manitoba shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ontario shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ontario shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ottawa & Montreal shared true NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Toronto shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Quebec shared false NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ottawa & Montreal shared true NOT_INSTALLED 
2023-01-31 16:05:03.776  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Quebec shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Saskatchewan shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Saskatchewan shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Mexico shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Baja California and Sonora shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Baja California & Sonora shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Chihuahua shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Chihuahua shared false NOT_INSTALLED 
2023-01-31 16:05:03.777  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Durango and Coahuila shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Coahuila, Durango, Sinaloa shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Nuevo Leon and Tamaulipas shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Nuevo Leon & Tamaulipas shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Central West Sinaloa and Nayarit shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Aguascalientes, Nayarit, Zacatecas shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Jalisco & Colima shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Mexico City and Central Mexico shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ciudad de México shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== San Luis Potosí & Guanajuato shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mexico Central North shared false NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.778  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Michoacan and Guerrero shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Michoacán & Guerrero shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Central East shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mexico Central South shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Oaxaca shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Veracruz de Ignacio de la Llave shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mexico Yucatan and Mexico East shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Yucatàn Peninsular shared false NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.779  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = South America shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Argentina shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Argentina North shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Buenos Aires Province shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== New Cuyo Region, Center Region and Big North Argentinian shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Argentina South shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Patagonian Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.780  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Bolivia shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bolivia shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Brazil shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Brasilia Amazonas Roraima Acre Rondonia Mato Grosso Federal District Goiás Pará shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Center West Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Amazonas, Roraima, Pará, Amapá, Acre, Rondônia and Mato Grosso shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Maranhao Ceará Tocantins shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Maranhâo, Tocantins, Piauí and Ceará shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Bahia Sergipe Alagoas Pernambuco Rio Grande do Norte Paraíba shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Río Gande do Norte, Paraíba, Pernanbuco, Alagoas and Sergipe shared false NOT_INSTALLED 
2023-01-31 16:05:03.781  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Bahia shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Rio de Janeiro Minas Gerais shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== North Minas Gerais shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Rio de Janeiro shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Belo Horizonte shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Sao Paulo shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== East Sao Paulo shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== North Sao Paulo shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Sao Paulo shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== South Sao Paulo shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== West Sao Paulo shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Mato Grosso do Sul Paraná shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mato Grosso do Sul shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Paraná shared false NOT_INSTALLED 
2023-01-31 16:05:03.782  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brazil Rio Grande do Sul Santa Catarina shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== East Santa Catarina and Rio Grande do Sul shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== West Santa Catarina and Rio Grande do Sul shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Chile shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Chile South shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Maule Region and South of Chile shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Chile North shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== O'higgins Region, Metropolitan Region and North of Chile shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Colombia shared false NOT_INSTALLED 
2023-01-31 16:05:03.783  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === West Colombia shared false NOT_INSTALLED 
2023-01-31 16:05:03.784  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === East Colombia shared false NOT_INSTALLED 
2023-01-31 16:05:03.784  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.784  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Ecuador shared false NOT_INSTALLED 
2023-01-31 16:05:03.784  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ecuador shared false NOT_INSTALLED 
2023-01-31 16:05:03.784  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == French Guiana shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === French Guiana shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Guyana shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Guyana shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Paraguay shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Paraguay shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Peru shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Peru shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Suriname shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Suriname shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Uruguay shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Uruguay shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Venezuela shared false NOT_INSTALLED 
2023-01-31 16:05:03.787  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Venezuela shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Central America shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Belize shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Belize shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Costa Rica shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Costa Rica shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Guatemala shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Guatemala shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections North America (NAM) shared true NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Nicaragua shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Nicaragua shared false NOT_INSTALLED 
2023-01-31 16:05:03.788  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Panama shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Panama shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Honduras shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Honduras shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == El Salvador shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === El Salvador shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Caribbean Countries shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Lesser Antilles Territories shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Caribbean Countries shared false NOT_INSTALLED 
2023-01-31 16:05:03.789  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Ferry Connections South America (AMERICAS) shared true NOT_INSTALLED 
2023-01-31 16:05:03.790  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Europe shared false PARTIALLY_INSTALLED 
2023-01-31 16:05:03.790  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Albania shared false NOT_INSTALLED 
2023-01-31 16:05:03.790  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Albania shared false NOT_INSTALLED 
2023-01-31 16:05:03.790  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.790  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Armenia shared false NOT_INSTALLED 
2023-01-31 16:05:03.790  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Armenia shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Austria shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Austria Alps shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Austria North-East and Vienna shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Azerbaijan shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Azerbaijan shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Belarus shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Belarus shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Belgium shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Belgium North shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Belgium South shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Bosnia and Herzegovina shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bosnia and Herzegovina shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Bulgaria shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bulgaria shared false NOT_INSTALLED 
2023-01-31 16:05:03.791  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Croatia shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Croatia shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Cyprus shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Cyprus shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Czech Republic shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North-West-Czechia shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South-East-Czechia shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Denmark shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Zealand and Bornholm shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Jutland and Funen shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Estonia shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Estonia shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Finland shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Turku and Tampere Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Helsinki and Mikkeli Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.792  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Vaasa and Oulu Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Rovaniemi and Joensuu Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Georgia shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Georgia shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Germany shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Germany East shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Berlin & North-East Germany shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Central Germany shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Lower Saxony South - Thuringia - Middle Elbe shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Germany Southeast shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Franconia shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Bavaria shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Germany Southwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Rhineland-Palatinate & Saarland shared false NOT_INSTALLED 
2023-01-31 16:05:03.793  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Stuttgart Region & Swabia shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Black Forest & Allgäu shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Germany West shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Westphalia & Ruhr Area shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Lower Rhine & Eifel shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Hessian and Metropol Region Frankfurt shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Germany Northwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Hamburg Metropol Region & Schleswig-Holstein shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Bremen & Lower Saxony West shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Greece shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Greece North and West shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Greece South - Crete - Aegean Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Hungary shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Hungary shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Iceland shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Iceland shared false NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Arctic (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.794  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Ireland shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Dublin Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ireland Rural Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Latvia shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Latvia shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Lithuania shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Lithuania shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Luxembourg shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Luxembourg shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == North Macedonia shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North Macedonia shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Malta shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Malta shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Moldova shared false NOT_INSTALLED 
2023-01-31 16:05:03.795  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Moldova shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Montenegro shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Montenegro shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Norway shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Oslo and Lillehammer Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bergen and Kristiansand Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Trondheim and Tromsø Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Poland shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Central East Poland shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Central West Poland shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Poland shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North Poland shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Portugal shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Portugal North shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Portugal Interior and Algarve shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Portugal Centre, Azores and Madeira Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.796  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Romania shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === West Romania shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === East Romania shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Serbia shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Serbia shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Slovakia shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Slovakia shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Slovenia shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Slovenia shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Sweden shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Stockholm and South East Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Göteborg and Malmö Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Norrland coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.797  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Norrland Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Netherlands shared false PARTIALLY_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Netherlands North - IJsselmeer shared false INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Netherlands Coastal Region shared false INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Netherlands Mid and South shared false INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Turkey shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Turkey East shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Black Sea Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== South and East Anatolia Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Turkey West shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Marmara Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Aegean Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Turkey Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Central-West Turkey shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Central Anatolia Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.798  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ankara shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Ukraine shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ukraine West shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ukraine Center shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ukraine East shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Crimea shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == United Kingdom shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === UK North shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Scotland shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Yorkshire and the Humber and North shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Merseyside and Greater Manchester Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === UK South shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== England South West shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== East of England shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== England South East shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Greater London shared false NOT_INSTALLED 
2023-01-31 16:05:03.799  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === UK Central Northern Ireland shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Wales and Northern Ireland shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== England West Midlands shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== England East Midlands shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Russian Federation shared false PARTIALLY_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia Ural West Siberia shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Western Siberia shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Central Siberia shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia Kama Volga shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Volga-Kama shared false NOT_INSTALLED 
2023-01-31 16:05:03.800  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Western Ural shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia Federal Districts South North Caucasus shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Russia South shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Northern Caucasus shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia Federal Districts Northwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Kaliningrad shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Russia North shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Russia North-West shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia Federal Districts Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Moscow city shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Moscow region shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Russia West shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia East Siberia Far East shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Eastern Siberia shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Russia Far East shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Russia Volga Don shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Middle Volga shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Volga-Don shared false NOT_INSTALLED 
2023-01-31 16:05:03.801  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Arctic (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (EUR) shared false INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Switzerland, Liechtenstein shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Switzerland North-East and Liechtenstein shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Switzerland Alps shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Spain, Andorra shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Spain Northeast / Andorra shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Navarra, Aragón, Tarragona and Lleida shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Barcelona and Girona shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Valencia Region and Balearic Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Spain South / Gibraltar shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Region of Madrid and Centre shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== East Andalusia, Albace and Murcia shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== West Andalusia, Ceuta and Melilla shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Canary Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Spain Northwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Galicia and Asturias shared false NOT_INSTALLED 
2023-01-31 16:05:03.802  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Extremadura and Castilla-León East shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Cantabria, País Vasco and Castilla-León North shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == France, Monaco shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === France Northeast shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== France North shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Paris Francilienne shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ile-de-France Marne and Ardennes shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== France East shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Alsace shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === France South Corsica / Monaco shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Lyons and Saint-Etienne shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Rhone Valley and Alpes shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mediterranean West shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mediterranean East shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Mediterranean Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.803  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === France Southwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Poitou-Charentes shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Limousin Languedoc shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Aquitaine South shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Midi-Pyrenees South shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === France Northwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Normandy shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Brittany shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Loire Valley shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === France Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== France Centre shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Burgundy and Jura shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Auvergne Cevennes shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Europe (EUR) shared true NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Italy, San Marino shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Italy Northeast / San Marino shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Emilia - East Lombardia - Trentino - Verona shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Veneto - Friuli shared false NOT_INSTALLED 
2023-01-31 16:05:03.804  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Romagna - San Marino - Marche - Umbria shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Italy South Sardinia Sicily shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Sardegna shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Puglia - Basilicata - North Calabria shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Sicilia - South Calabria shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Italy Northwest shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Piemonte - Valle D’Aosta - West Liguria shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Milano Area shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Italy Central / Vatican shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Toscana - East Liguria shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Lazio shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Campania - Abruzzo - Molise shared false NOT_INSTALLED 
2023-01-31 16:05:03.805  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Africa shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Algeria shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Algeria Mediterranean Coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Algerian Sahara Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Angola shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Angola shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Benin shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Benin shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Botswana shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Botswana shared false NOT_INSTALLED 
2023-01-31 16:05:03.806  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Burkina Faso shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Burkina Faso shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Burundi shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Burundi shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Cameroon shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Cameroon shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Republic of the Congo shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Republic of the Congo shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Cote d'Ivoire shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ivory Coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Democratic Republic of the Congo shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Democratic Republic of the Congo shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Egypt shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Cairo Metropolitan Area shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Egypt main shared false NOT_INSTALLED 
2023-01-31 16:05:03.807  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Ethiopia shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ethiopia shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Gabon shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Gabon shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Gambia shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Gambia shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Ghana shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ghana shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Guinea shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Guinea shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Kenya shared false NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.808  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kenya shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Malawi shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Malawi shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Mali shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mali shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Mauritania shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mauritania shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Morocco shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Morocco Mediterranean and Atlas shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Morocco Sahara Region shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Mozambique shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mozambique shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Namibia shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Namibia shared false NOT_INSTALLED 
2023-01-31 16:05:03.809  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Niger shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Niger shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Nigeria shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Nigeria shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Rwanda shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Rwanda shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Senegal shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Senegal shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Sudan shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Sudan shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Tanzania shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Tanzania shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Togo shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Togo shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Tunisia shared false NOT_INSTALLED 
2023-01-31 16:05:03.810  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Tunisia shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Uganda shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Uganda shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Zambia shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Zambia shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Zimbabwe shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Zimbabwe shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Central African Republic shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Central African Republic shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Djibouti shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Djibouti shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Eritrea shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Eritrea shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Guinea-Bissau shared false NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.811  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Guinea-Bissau shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Liberia shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Liberia shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Libya shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Libya shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Madagascar shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Madagascar shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Sierra Leone shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Sierra Leone shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Somalia shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Somalia shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == South Sudan shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Sudan shared false NOT_INSTALLED 
2023-01-31 16:05:03.812  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Chad shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Chad shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Equatorial Guinea, Sao Tome and Principe shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Equatorial Guinea and Sao Tome and Principe shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == South Africa, Lesotho, Swaziland shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Africa East / Swaziland / Lesotho shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Johannesburg shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Kwazulu & Lesotho & Swaziland shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Africa West shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Northern Cape and Limpopo shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Western Cape and Free State shared false NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.813  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == African Indian Ocean Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === African Indian Ocean Islands shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Central Asia shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Kazakhstan shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kazakhstan shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Kyrgyzstan shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kyrgyzstan shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Tajikistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Tajikistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.814  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Afghanistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Afghanistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Pakistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Pakistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Turkmenistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Turkmenistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Uzbekistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Uzbekistan shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Israel shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Israel shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Israel & Palestine shared false NOT_INSTALLED 
2023-01-31 16:05:03.815  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Middle East shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Iraq shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Iraq shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Jordan shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Jordan shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Kuwait shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kuwait shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Lebanon shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Lebanon shared false NOT_INSTALLED 
2023-01-31 16:05:03.816  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Saudi Arabia shared false NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Saudi Arabia East shared false NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Red Sea coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Yemen shared false NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Yemen shared false NOT_INSTALLED 
2023-01-31 16:05:03.817  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Syrian Arab Republic shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Syrian Arab Republic shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Iran shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Iran shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Bahrain, Qatar shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bahrain & Qatar shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Israel, State of Palestine shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Mediterranean (EMEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == United Arab Emirates, Oman shared false NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Africa (MEA) shared true NOT_INSTALLED 
2023-01-31 16:05:03.818  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === UAE & Oman shared false NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Oceania shared false NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Australia shared false NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Western Australia shared false NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Western Australia shared false NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Northern Territory shared false NOT_INSTALLED 
2023-01-31 16:05:03.819  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Northern Territory shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Australia shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== South Australia shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Queensland shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Brisbane & Gold Coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Queensland shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Victoria shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Melbourne shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Victoria shared false NOT_INSTALLED 
2023-01-31 16:05:03.820  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Tasmania shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Tasmania shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === New South Wales shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Sydney shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Canberra & New South Wales shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == New Zealand shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South Pacific (OCE) shared true NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North Island shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Island shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Melanesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South Pacific (OCE) shared true NOT_INSTALLED 
2023-01-31 16:05:03.821  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Melanesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Micronesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South Pacific (OCE) shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Micronesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Polynesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections South Pacific (OCE) shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Polynesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = India shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == India shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === West Bengal shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Karnataka shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.822  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Andhra Pradesh shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Kerala shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Odisha shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Gujarat shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Tamil Nadu shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Maharashtra and Goa shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.823  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.824  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Asia Pacific shared false NOT_INSTALLED 
2023-01-31 16:05:03.824  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == China shared false NOT_INSTALLED 
2023-01-31 16:05:03.824  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === China shared false NOT_INSTALLED 
2023-01-31 16:05:03.824  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Cambodia shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Cambodia shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Indonesia shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Indonesia West shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Jakarta, West Java, Banten shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Sumatra shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Indonesia Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Yogyakarta, Central Java, East Java shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Indonesia East shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Bali, Lombok, Kalimantan, Sulawesi, Maluku, Papua shared false NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.825  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Philippines shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Luzon shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Visayas & Mindanao shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Malaysia shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Malaysia West Coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Malaysia East Coast shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Borneo shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Singapore shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Singapore shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Taiwan shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Taiwan North shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Taiwan Middle West shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Taiwan South East shared false NOT_INSTALLED 
2023-01-31 16:05:03.826  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Thailand shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Thailand South shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Bangkok Metropolitan shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Thailand West and South shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Thailand East shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Thailand North shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Thailand Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Thailand North shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Thailand East shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Thailand Northeast shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region ==== Thailand Middle Northeast shared false NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.827  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Vietnam shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Vietnam North shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Vietnam Central shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Vietnam South shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Myanmar shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Myanmar shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Maldives shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Maldives shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Mongolia shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Mongolia shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == South Korea shared false NOT_INSTALLED 
2023-01-31 16:05:03.828  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === South Korea shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Bangladesh shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bangladesh shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Brunei Darussalam shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Brunei Darussalam shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Bhutan shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Bhutan shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == India shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === India shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Japan shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Japan shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Laos shared false NOT_INSTALLED 
2023-01-31 16:05:03.829  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Laos shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Sri Lanka shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Sri Lanka shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections India (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Nepal shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Nepal shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == North Korea shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === North Korea shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Timor-Leste shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Timor-Leste shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Oceania (APAC2) shared true NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == Hong Kong, Macau shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Hong Kong & Macao shared false NOT_INSTALLED 
2023-01-31 16:05:03.830  2704-2704  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Ferry Connections Asia (APAC2) shared true NOT_INSTALLED 


// bmw && 41307
2023-01-31 16:34:43.038  3633-3633  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, Installed region
2023-01-31 16:34:43.057  3633-3633  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region = Asia Pacific shared false INSTALLED 
2023-01-31 16:34:43.058  3633-3633  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region == JAPAN shared false INSTALLED 
2023-01-31 16:34:43.058  3633-3633  InstalledR...sViewModel com.tomtom.navapp                    E  TTDebug, region === Japan shared false INSTALLED 