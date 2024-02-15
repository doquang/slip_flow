#include "slip_flowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
slip_flowApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

slip_flowApp::slip_flowApp(InputParameters parameters) : MooseApp(parameters)
{
  slip_flowApp::registerAll(_factory, _action_factory, _syntax);
}

slip_flowApp::~slip_flowApp() {}

void 
slip_flowApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<slip_flowApp>(f, af, s);
  Registry::registerObjectsTo(f, {"slip_flowApp"});
  Registry::registerActionsTo(af, {"slip_flowApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
slip_flowApp::registerApps()
{
  registerApp(slip_flowApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
slip_flowApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  slip_flowApp::registerAll(f, af, s);
}
extern "C" void
slip_flowApp__registerApps()
{
  slip_flowApp::registerApps();
}
