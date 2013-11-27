/*
    ${NAME} Controller
 */
#include "esp.h"

/*
    Create a new resource in the database
 */ 
static void create${TITLE}() { 
    if (updateRec(createRec("${NAME}", params()))) {
        flash("inform", "New ${NAME} Created");
        renderView("${NAME}/${NAME}-list");
    } else {
        flash("error", "Cannot Create ${TITLE}");
        renderView("${NAME}/${NAME}-edit");
    }
}

/*
    Prepare a template for editing a resource
 */
static void edit${TITLE}() { 
    readRec("${NAME}", param("id"));
}

/*
    Get a resource
 */ 
static void get${TITLE}() { 
    readRec("${NAME}", param("id"));
    renderView("${NAME}/${NAME}-edit");
}

/*
    Initialize a new resource for the client to complete
 */
static void init${TITLE}() { 
    createRec("${NAME}", 0);
    renderView("${NAME}/${NAME}-edit");
}

/*
    List the resources in this group
 */ 
static void list${TITLE}() { 
    renderView("${NAME}/${NAME}-list");
}

/*
    Remove a resource identified by the "id" parameter
 */
static void remove${TITLE}() { 
    if (removeRec("${NAME}", param("id"))) {
        flash("inform", "${TITLE} Removed");
    }
    redirect("list");
}

/*
    Update an existing resource in the database
    If "id" is not defined, this is the same as a create
    Also we tunnel delete here if the user clicked delete
 */
static void update${TITLE}() { 
    if (smatch(param("submit"), "Delete")) {
        removePost();
    } else {
        if (updateFields("${NAME}", params())) {
            flash("inform", "${TITLE} Updated Successfully");
            redirect("list");
        } else {
            flash("error", "Cannot Update ${TITLE}");
            renderView("${NAME}/${NAME}-edit");
        }
    }
}

static void common(HttpConn *conn) {
}

/*
    Dynamic module initialization
 */
ESP_EXPORT int esp_controller_${APP}_${NAME}(HttpRoute *route, MprModule *module) {
    espDefineBase(route, common);
    espDefineAction(route, "${NAME}-create", create${TITLE});
    espDefineAction(route, "${NAME}-remove", remove${TITLE});
    espDefineAction(route, "${NAME}-edit", edit${TITLE});
    espDefineAction(route, "${NAME}-get", get${TITLE});
    espDefineAction(route, "${NAME}-init", init${TITLE});
    espDefineAction(route, "${NAME}-list", list${TITLE});
    espDefineAction(route, "${NAME}-update", update${TITLE});
    espDefineAction(route, "${NAME}-cmd-", list${TITLE});
${DEFINE_ACTIONS}    
#if SAMPLE_VALIDATIONS
    Edi *edi = espGetRouteDatabase(route);
    ediAddValidation(edi, "present", "${NAME}", "title", 0);
    ediAddValidation(edi, "unique", "${NAME}", "title", 0);
    ediAddValidation(edi, "banned", "${NAME}", "body", "(swear|curse)");
    ediAddValidation(edi, "format", "${NAME}", "phone", "/^\(?([0-9]{3})\)?[-. ]?([0-9]{3})[-. ]?([0-9]{4})$/");
#endif
    return 0;
}
