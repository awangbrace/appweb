Spy Filter Sample
===

This sample shows how to create an Appweb input filter.

Requirements
---
* [Appweb](https://embedthis.com/appweb/download.html)
* [MakeMe Build Tool](https://embedthis.com/makeme/download.html)

To build:
---
    me 

To run:
---
    me run

The server listens on port 8080. Use the "http" client utility to issue a form request:
 
     http --show --form "hello" http://localhost:8080/index.html

This will do a POST request with the text "hello" in the body. The show option will display the response
Http headers. If "hello" is in the body, then the header "X-Greeting: found" will be present. Otherwise,
the header will be set to "missing".

Code:
---
* [spyFilter.c](spyFilter.c) - Spy Filter source code
* [appweb.conf](appweb.conf) - Appweb server configuration file
* [index.html](index.html) - Web page to serve
* [start.me](start.me) - MakeMe build instructions

Documentation:
---
* [Appweb Documentation](https://embedthis.com/appweb/doc/index.html)
* [Creating Handlers](https://embedthis.com/appweb/doc/programmers/handlers.html)
* [Creating Modules](https://embedthis.com/appweb/doc/programmers/modules.html)
* [Configuration Directives](https://embedthis.com/appweb/doc/users/configuration.html#directives)

See Also:
---
* [simple-handler - Simple Appweb handler](../simple-handler/README.md)
* [typical-server - Fully featured server and embedding API](../typical-server/README.md)
