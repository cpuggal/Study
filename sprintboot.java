package com.javaguides.patterns;

import java.util.ArrayList;
import java.util.List;

import com.fasterxml.jackson.databind.annotation.JsonSerialize;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;


@RestController
public class PortfolioController {
    private List<PortfolioHoldings> portfolioHoldingsList = new ArrayList<PortfolioHoldings>();

    // default constructor for testing and storing data
    PortfolioController() {
        portfolioHoldingsList.add(new PortfolioHoldings("10-09-1987", "Infosys",
                10, "Growth"));
        portfolioHoldingsList.add(new PortfolioHoldings("10-11-1987", "TCS",
                100, "Growth"));
        portfolioHoldingsList.add(new PortfolioHoldings("02-12-1987", "Apple",
                110, "Growth"));
        portfolioHoldingsList.add(new PortfolioHoldings("10-09-1990", "IBM",
                200, "Growth"));
        portfolioHoldingsList.add(new PortfolioHoldings("10-09-1989", "Samsung",
                500, "Growth"));
    }
    @GetMapping(value = "getPortfolio", produces = MediaType.APPLICATION_JSON_VALUE)
    //@GetMapping(value = "getPortfolio", produces = MediaType.APPLICATION_XML_VALUE)
    public PortfolioHoldings getPortfolio() {
        return new PortfolioHoldings("10-09-1987", "Nokia", 10, "Growth");
    }

    // List of Information
    // Test: localhost:8080/getAllPortfolios
    @GetMapping("getAllPortfolios")
    public List<PortfolioHoldings> getAllPortfolios() {
        return portfolioHoldingsList;
    }

    // Get Path Params
    // Test: localhost:8080/getPortfolio/TCS
    @GetMapping("/getPortfolio/{org}")
    public PortfolioHoldings getPortfolioForOrg(
            @PathVariable("org") String organization) {
        for (PortfolioHoldings p : portfolioHoldingsList) {
            if (p.getSecurity().equals(organization))
                return p;
        }
        return new PortfolioHoldings();
    }

    // Request Params
    // Test: localhost:8080/getPortfolio?org=IBM
    @GetMapping("/getPortfolio")
    public ResponseEntity getPortfolioForOrgReqParam(
            @RequestParam("org") String organization) {
        HttpHeaders headers = new HttpHeaders();
        headers.add("Content-Type", "application/json");
//        ResponseEntity.BodyBuilder responseBuilder = ResponseEntity.ok().headers(headers);

        for (PortfolioHoldings portfolio : portfolioHoldingsList) {
            if (portfolio.getSecurity().equals(organization))
//                return responseBuilder.body(p);
                return new ResponseEntity<>(portfolio, headers, HttpStatus.OK);
        }
//        return responseBuilder.body(new EmptyJsonBody());
        return new ResponseEntity<>(headers, HttpStatus.BAD_REQUEST);
    }

    // Post Path Params
    // Test: localhost:8080/setPortfolio/TCS/150
    @PostMapping("/setPortfolio/{org}/{qty}")
    public ResponseEntity setPortfolioQuantity(
            @PathVariable("org") String organization,
            @PathVariable("qty") Integer quantity) {
        HttpHeaders headers = new HttpHeaders();
        headers.add("Content-type", "application/json");

        for (PortfolioHoldings portfolio : portfolioHoldingsList) {
            if (portfolio.getSecurity().equals(organization)) {
                portfolio.setQuantity(quantity);
                return new ResponseEntity<>(portfolio, headers, HttpStatus.OK);
            }
        }
        return new ResponseEntity<>(headers, HttpStatus.BAD_REQUEST);
    }

    // test api for json
    @PostMapping("/setPortfolio/test")
    public ResponseEntity setPortfolioQuantity1(
            @RequestBody String json) {
        HttpHeaders headers = new HttpHeaders();
        headers.add("Content-type", "application/json");
        return new ResponseEntity<>(json, headers, HttpStatus.BAD_REQUEST);
    }
}
