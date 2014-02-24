/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 2.1.5.qualifier.
* Used org.franca.core 0.8.10.201309262002.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include "LeafInterfaceDBusStubAdapter.h"
#include <commonapi/tests/managed/LeafInterface.h>

namespace commonapi {
namespace tests {
namespace managed {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createLeafInterfaceDBusStubAdapter(
                   const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
                   const std::string& commonApiAddress,
                   const std::string& interfaceName,
                   const std::string& busName,
                   const std::string& objectPath,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyConnection,
                   const std::shared_ptr<CommonAPI::StubBase>& stubBase) {
    return std::make_shared<LeafInterfaceDBusStubAdapter>(factory, commonApiAddress, interfaceName, busName, objectPath, dbusProxyConnection, stubBase);
}

INITIALIZER(registerLeafInterfaceDBusStubAdapter) {
    CommonAPI::DBus::DBusFactory::registerAdapterFactoryMethod(LeafInterface::getInterfaceId(),
                                                               &createLeafInterfaceDBusStubAdapter);
}



LeafInterfaceDBusStubAdapterInternal::~LeafInterfaceDBusStubAdapterInternal() {
    deactivateManagedInstances();
    LeafInterfaceDBusStubAdapterHelper::deinit();
}

void LeafInterfaceDBusStubAdapterInternal::deactivateManagedInstances() {

}

const char* LeafInterfaceDBusStubAdapterInternal::getMethodsDBusIntrospectionXmlData() const {
    static const std::string introspectionData =
        "<method name=\"getInterfaceVersion\">\n"
            "<arg name=\"value\" type=\"uu\" direction=\"out\" />"
        "</method>\n"
        "<method name=\"testLeafMethod\">\n"
            "<arg name=\"inInt\" type=\"i\" direction=\"in\" />\n"
            "<arg name=\"inString\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"methodError\" type=\"i\" direction=\"out\" />\n"
            "<arg name=\"outInt\" type=\"i\" direction=\"out\" />\n"
            "<arg name=\"outString\" type=\"s\" direction=\"out\" />\n"
        "</method>\n"

    ;
    return introspectionData.c_str();
}

CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        LeafInterfaceStub,
        CommonAPI::Version
        > LeafInterfaceDBusStubAdapterInternal::getLeafInterfaceInterfaceVersionStubDispatcher(&LeafInterfaceStub::getInterfaceVersion, "uu");



CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    LeafInterfaceStub,
    std::tuple<int32_t, std::string>,
    std::tuple<LeafInterface::testLeafMethodError, int32_t, std::string>
    > LeafInterfaceDBusStubAdapterInternal::testLeafMethodStubDispatcher(&LeafInterfaceStub::testLeafMethod, "iis");





const LeafInterfaceDBusStubAdapterHelper::StubDispatcherTable& LeafInterfaceDBusStubAdapterInternal::getStubDispatcherTable() {
    return stubDispatcherTable_;
}


LeafInterfaceDBusStubAdapterInternal::LeafInterfaceDBusStubAdapterInternal(
        const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
        const std::string& commonApiAddress,
        const std::string& dbusInterfaceName,
        const std::string& dbusBusName,
        const std::string& dbusObjectPath,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusConnection,
        const std::shared_ptr<CommonAPI::StubBase>& stub):
        CommonAPI::DBus::DBusStubAdapter(
                factory,
                commonApiAddress,
                dbusInterfaceName,
                dbusBusName,
                dbusObjectPath,
                dbusConnection,
                false),
        LeafInterfaceDBusStubAdapterHelper(
            factory,
            commonApiAddress,
            dbusInterfaceName,
            dbusBusName,
            dbusObjectPath,
            dbusConnection,
            std::dynamic_pointer_cast<LeafInterfaceStub>(stub),
            false),
        stubDispatcherTable_({
            { { "testLeafMethod", "is" }, &commonapi::tests::managed::LeafInterfaceDBusStubAdapterInternal::testLeafMethodStubDispatcher }
            }) {

    stubDispatcherTable_.insert({ { "getInterfaceVersion", "" }, &commonapi::tests::managed::LeafInterfaceDBusStubAdapterInternal::getLeafInterfaceInterfaceVersionStubDispatcher });
}

} // namespace managed
} // namespace tests
} // namespace commonapi
