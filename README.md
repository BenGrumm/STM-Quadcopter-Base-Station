# STM-Quadcopter-Base-Station
 Base station for telemetry from STM base quadcopter.

## Building

## Testing

Add cpputest with build for docker.
- docker build -t unit-tests-image -f Dockerfile .
- docker run --rm unit-tests-image

Currently tests only working on linux (wsl) so building after installing cpputest.
- Run by using commands in docker file
