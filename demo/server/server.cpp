#include <reactive/web/application.hpp>
#include <reactive/http/server.hpp>

int main(int argc, char const *argv[])
{
    reactive::web::application app;

    app.match("/hello/:pseudo", [] (
        const reactive::http::request& req_,
        const reactive::web::router::parameters& params_,
        reactive::http::response& res_
    ) -> void {

        res_.setStatusCode(reactive::http::status::OK);
        res_.setContent("Hello " + params_.get("pseudo"));

    }).method("GET").constrain("pseudo", "[a-zA-Z0-9]{3,50}");

    reactive::http::server* server = new reactive::http::server(app);
    server->run();

    return 0;
}
