// Copyright (c) 2014-2019 Coin Sciences Ltd
// Meliponariod code distributed under the GPLv3 license, see COPYING file.

#ifndef MELIPONARIO_V8ENGINE_H_
#define MELIPONARIO_V8ENGINE_H_

#include "filters/ifiltercallback.h"
#include "rpc/rpcserver.h"
//#include "json/json_spirit.h"
#include <v8.h>

namespace mc_v8
{
class V8Filter;

/**
 * Interface to the Google V8 engine to create and run filters.
 */
class V8Engine
{
  public:
    ~V8Engine();

    /**
     * Initialize the V8 engine.
     *
     * @param strResult Reason for failure if unsuccessful.
     * @return          MC_ERR_NOERROR if successful, MC_ERR_INTERNAL_ERROR if not.
     */
    int Initialize(IFilterCallback *filterCallback, std::string &strResult);

    v8::Isolate *GetIsolate()
    {
        return m_isolate;
    }

    IFilterCallback *GetFilterCallback()
    {
        return m_filterCallback;
    }

    /**
     * Create a new filter.
     *
     * @param script         The filter JS code.
     * @param main_name      The expected name of the filtering function in the script.
     * @param callback_names A list of callback function names to register for the filter.
     *                       If empty, register no callback functions.
     * @param filter         The filter object to initialize.
     * @param strResult      Reason for failure if unsuccessful.
     * @return               MC_ERR_INTERNAL_ERROR if the engine failed, MC_ERR_NOERROR otherwise.
     */
    int CreateFilter(std::string script, std::string main_name, std::vector<std::string> &callback_names,
                     V8Filter *filter, std::string &strResult);

    /**
     * Run the filter function in the JS script.
     *
     * @param filter    The user-defined filter to use.
     * @param strResult Reason for script failure or rejection.
     * @return          MC_ERR_INTERNAL_ERROR if the engine failed, MC_ERR_NOERROR otherwise.
     */
    int RunFilter(V8Filter *filter, std::string &strResult);

    /**
     * Abort the currently running filter (if any).
     *
     * @param filter    The filter to abort.
     * @param reason    The reason the filter is being terminated.
     */
    void TerminateFilter(V8Filter *filter, std::string reason);

    std::string TerminationReason() const
    {
        return m_reason;
    }

  private:
    IFilterCallback *m_filterCallback = nullptr;
    v8::Isolate *m_isolate = nullptr;
    static std::unique_ptr<v8::Platform> m_platform;
    static v8::Isolate::CreateParams m_createParams;
    static bool m_isV8Initialized;
    std::string m_reason;

    static void InitializeV8();
};

} // namespace mc_v8

#endif /* MELIPONARIO_V8ENGINE_H_ */
