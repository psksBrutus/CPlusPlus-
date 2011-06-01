//
//  Plugin.h
//  OSM_Konverter
//
//  Created by Marcel Radischat on 01.06.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include "imports.h"

class OSMObject;
class ConvertController;

class Plugin{
    std::string name;
	
public:
	Plugin( const char* name );
	virtual ~Plugin();
    
	const std::string& GetName() const { return name; }
    
	//! Rückgabe: Anzahl der registrierten Klassen
	virtual int RegisterClasses( ConvertController& controller ) = 0;
    
}; // end class Plugin