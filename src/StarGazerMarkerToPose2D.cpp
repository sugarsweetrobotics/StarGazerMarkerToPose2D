// -*- C++ -*-
/*!
 * @file  StarGazerMarkerToPose2D.cpp
 * @brief Translator StarGazerMarkerInfo to TimedPose2D
 * @date $Date$
 *
 * $Id$
 */

#include "StarGazerMarkerToPose2D.h"

// Module specification
// <rtc-template block="module_spec">
static const char* stargazermarkertopose2d_spec[] =
  {
    "implementation_id", "StarGazerMarkerToPose2D",
    "type_name",         "StarGazerMarkerToPose2D",
    "description",       "Translator StarGazerMarkerInfo to TimedPose2D",
    "version",           "1.0.0",
    "vendor",            "Sugarsweetrobotics",
    "category",          "Sensor",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    // Widget
    "conf.__widget__.debug", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
StarGazerMarkerToPose2D::StarGazerMarkerToPose2D(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_infoIn("info", m_info),
    m_poseOut("currentPose", m_pose)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
StarGazerMarkerToPose2D::~StarGazerMarkerToPose2D()
{
}



RTC::ReturnCode_t StarGazerMarkerToPose2D::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("info", m_infoIn);
  
  // Set OutPort buffer
  addOutPort("currentPose", m_poseOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  // </rtc-template>
  m_infoIn.addConnectorDataListener(ON_BUFFER_WRITE,
				    new MarkerInfoListener(this));
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t StarGazerMarkerToPose2D::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void StarGazerMarkerToPose2DInit(RTC::Manager* manager)
  {
    coil::Properties profile(stargazermarkertopose2d_spec);
    manager->registerFactory(profile,
                             RTC::Create<StarGazerMarkerToPose2D>,
                             RTC::Delete<StarGazerMarkerToPose2D>);
  }
  
};


