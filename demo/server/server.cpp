#include <reactive/web/application.hpp>
#include <reactive/http/server.hpp>
#include <reactive/web/middleware/logger.hpp>

int main(int argc, char const *argv[])
{
    reactive::web::application app;

    app.middleware(new reactive::web::middleware::logger());

    app.match("GET", "/users", [] (
        const reactive::http::request& req_,
        const reactive::web::router::parameters& params_,
        reactive::http::response& res_
    ) -> void {
        res_.setStatusCode(reactive::http::status::OK);
        res_.setContent("Hello " + params_.get("pseudo"));
        res_.end();
    });

    reactive::http::server* server = new reactive::http::server(app);
    server->run();

    return 0;
}
