//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "slip_flowTestApp.h"
#include "slip_flowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
slip_flowTestApp::validParams()
{
  InputParameters params = slip_flowApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

slip_flowTestApp::slip_flowTestApp(InputParameters parameters) : MooseApp(parameters)
{
  slip_flowTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

slip_flowTestApp::~slip_flowTestApp() {}

void
slip_flowTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  slip_flowApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"slip_flowTestApp"});
    Registry::registerActionsTo(af, {"slip_flowTestApp"});
  }
}

void
slip_flowTestApp::registerApps()
{
  registerApp(slip_flowApp);
  registerApp(slip_flowTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
slip_flowTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  slip_flowTestApp::registerAll(f, af, s);
}
extern "C" void
slip_flowTestApp__registerApps()
{
  slip_flowTestApp::registerApps();
}
