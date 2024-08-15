# Function to update git submodules
function(update_git_submodules)
    message(STATUS "Updating git submodules...")
    execute_process(
        COMMAND git submodule update --init --recursive
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE result
    )

    if(NOT result EQUAL "0")
        message(FATAL_ERROR "Failed to update git submodules. Please check your Git configuration.")
    endif()
endfunction()

# Call the function to update git submodules
update_git_submodules()
