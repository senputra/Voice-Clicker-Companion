set(POCO_HEADERS ./Poco/DNSSD/include/
    ./Poco/DNSSD/Bonjour/include/
    ./Poco/DNSSD/Avahi/include/
    ./Poco/Net/include/
    ./Poco/Foundation/include/)

set(SERVICEDISCOVERY_API_DIR ./
    ${POCO_HEADERS})

find_file()